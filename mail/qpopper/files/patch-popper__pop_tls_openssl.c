--- popper/pop_tls_openssl.c.orig	2011-05-30 19:13:40 UTC
+++ popper/pop_tls_openssl.c
@@ -312,21 +312,31 @@ openssl_init ( pop_tls *pTLS, POP *pPOP 
      * concern. 
      */
     switch ( pPOP->tls_version ) {
+#ifdef OPENSSL_NO_SSL2
+        case QPOP_SSLv2:
+#endif
+#ifdef OPENSSL_NO_SSL3_METHOD
+        case QPOP_SSLv3:
+#endif
         case QPOP_TLSvDEFAULT:  /* unspecified */
         case QPOP_SSLv23:
             DEBUG_LOG0 ( pPOP, "...setting method to SSLv23_server_method" );
             pTLS->m_OpenSSLmeth = SSLv23_server_method();
             break;
 
+#ifndef OPENSSL_NO_SSL2
         case QPOP_SSLv2:       /* SSL version 2 only */
             DEBUG_LOG0 ( pPOP, "...setting method to SSLv2_server_method" );
             pTLS->m_OpenSSLmeth = SSLv2_server_method();
             break;
+#endif
 
+#ifndef OPENSSL_NO_SSL3_METHOD
         case QPOP_SSLv3:       /* SSL version 3 only */
             DEBUG_LOG0 ( pPOP, "...setting method to SSLv3_server_method" );
             pTLS->m_OpenSSLmeth = SSLv3_server_method();
             break;
+#endif
 
         case QPOP_TLSv1:       /* TLS version 1 only */
             DEBUG_LOG0 ( pPOP, "...setting method to TLSv1_server_method" );
@@ -537,7 +547,7 @@ openssl_handshake ( pop_tls *pTLS )
                           "%s session-id; cipher: %s (%s), %d bits",
                           VERSION, SSL_CIPHER_get_version(ciph),
                           pTLS->m_pPOP->client, pTLS->m_pPOP->ipaddr,
-                          ( pTLS->m_OpenSSLconn->hit ? "reused" : "new" ),
+                          ( SSL_CTX_sess_hits(pTLS->m_OpenSSLconn) ? "reused" : "new" ),
                           ( ciph_name != NULL ? ciph_name : "(none)" ),
                           get_cipher_description ( ciph, buf, sizeof(buf) ),
                           SSL_CIPHER_get_bits    ( ciph, &al_bits ) );
