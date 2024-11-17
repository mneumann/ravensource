--- libavcodec/libx265.c.orig	2024-08-04 23:23:18 UTC
+++ libavcodec/libx265.c
@@ -504,7 +504,13 @@ static int libx265_encode_frame(AVCodecC
 {
     libx265Context *ctx = avctx->priv_data;
     x265_picture x265pic;
-    x265_picture x265pic_out = { 0 };
+#if X265_BUILD >= 210
+    x265_picture x265pic_layers_out[MAX_SCALABLE_LAYERS];
+    x265_picture* x265pic_lyrptr_out[MAX_SCALABLE_LAYERS];
+#else
+    x265_picture x265pic_solo_out = { 0 };
+#endif
+    x265_picture* x265pic_out;
     x265_nal *nal;
     uint8_t *dst;
     int pict_type;
@@ -575,8 +581,16 @@ static int libx265_encode_frame(AVCodecC
         }
     }
 
+#if X265_BUILD >= 210
+    for (i = 0; i < MAX_SCALABLE_LAYERS; i++)
+        x265pic_lyrptr_out[i] = &x265pic_layers_out[i];
+
+    ret = ctx->api->encoder_encode(ctx->encoder, &nal, &nnal,
+                                   pic ? &x265pic : NULL, x265pic_lyrptr_out);
+#else
     ret = ctx->api->encoder_encode(ctx->encoder, &nal, &nnal,
-                                   pic ? &x265pic : NULL, &x265pic_out);
+                                   pic ? &x265pic : NULL, &x265pic_solo_out);
+#endif
 
     av_freep(&x265pic.quantOffsets);
 
@@ -604,10 +618,16 @@ static int libx265_encode_frame(AVCodecC
             pkt->flags |= AV_PKT_FLAG_KEY;
     }
 
-    pkt->pts = x265pic_out.pts;
-    pkt->dts = x265pic_out.dts;
+#if X265_BUILD >= 210
+    x265pic_out = x265pic_lyrptr_out[0];
+#else
+    x265pic_out = &x265pic_solo_out;
+#endif
+
+    pkt->pts = x265pic_out->pts;
+    pkt->dts = x265pic_out->dts;
 
-    switch (x265pic_out.sliceType) {
+    switch (x265pic_out->sliceType) {
     case X265_TYPE_IDR:
     case X265_TYPE_I:
         pict_type = AV_PICTURE_TYPE_I;
@@ -625,17 +645,17 @@ static int libx265_encode_frame(AVCodecC
     }
 
 #if X265_BUILD >= 130
-    if (x265pic_out.sliceType == X265_TYPE_B)
+    if (x265pic_out->sliceType == X265_TYPE_B)
 #else
-    if (x265pic_out.frameData.sliceType == 'b')
+    if (x265pic_out->frameData.sliceType == 'b')
 #endif
         pkt->flags |= AV_PKT_FLAG_DISPOSABLE;
 
-    ff_side_data_set_encoder_stats(pkt, x265pic_out.frameData.qp * FF_QP2LAMBDA, NULL, 0, pict_type);
+    ff_side_data_set_encoder_stats(pkt, x265pic_out->frameData.qp * FF_QP2LAMBDA, NULL, 0, pict_type);
 
-    if (x265pic_out.userData) {
-        memcpy(&avctx->reordered_opaque, x265pic_out.userData, sizeof(avctx->reordered_opaque));
-        av_freep(&x265pic_out.userData);
+    if (x265pic_out->userData) {
+        memcpy(&avctx->reordered_opaque, x265pic_out->userData, sizeof(avctx->reordered_opaque));
+        av_freep(&x265pic_out->userData);
     } else
         avctx->reordered_opaque = 0;
 
