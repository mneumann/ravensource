--- configure.py.orig	2024-07-17 13:00:43 UTC
+++ configure.py
@@ -46,6 +46,7 @@ from utils import SearchFiles
 parser = argparse.ArgumentParser()
 
 valid_os = ('win', 'mac', 'solaris', 'freebsd', 'openbsd', 'linux',
+            'netbsd',
             'android', 'aix', 'cloudabi', 'os400', 'ios')
 valid_arch = ('arm', 'arm64', 'ia32', 'mips', 'mipsel', 'mips64el', 'ppc',
               'ppc64', 'x64', 'x86', 'x86_64', 's390x', 'riscv64', 'loong64')
