# Created by: Peter Kieser <peter@kieser.ca>
# $FreeBSD$

PORTNAME=	spamdyke
PORTVERSION=	5.0.1
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://www.spamdyke.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qmail filter for monitoring and intercepting SMTP connections

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/tcprules:sysutils/ucspi-tcp

BROKEN_powerpc64=	Does not build: error: nested functions are disabled, use -fnested-functions to re-enable

USE_HARDENING=	pie:off relro:off

USES=		cpe qmail tar:tgz
WRKSRC=		${WRKDIR}/${DISTNAME}/spamdyke
GNU_CONFIGURE=	yes
ALL_TARGET=	spamdyke
USE_GCC=	any

OPTIONS_DEFINE=		TLS DEBUG DEBUG_EXCESSIVE DOCS
OPTIONS_DEFAULT=	TLS
DEBUG_DESC=		Enable debugging output
DEBUG_EXCESSIVE_DESC=	Enable excessive debugging output

TLS_CONFIGURE_ENABLE=	tls
TLS_USES=		ssl
TLS_LDFLAGS=		-L${OPENSSLLIB}
TLS_CFLAGS=		-I${OPENSSLINC}

DEBUG_CONFIGURE_ENABLE=			debug-output
DEBUG_EXCESSIVE_CONFIGURE_ENABLE=	excessive-output

PORTDOCS=	Changelog.txt FAQ.html GNUGPL.txt INSTALL.txt \
		README.html README_ip_file_format.html \
		README_rdns_directory_format.html README_rdns_file_format.html \
		UPGRADING.txt UPGRADING_version_3_to_version_4.txt

post-patch:
	@${REINPLACE_CMD} -e 's#^CFLAGS :=.*#CFLAGS = ${CFLAGS}#' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spamdyke ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/documentation/spamdyke.conf.example \
		${STAGEDIR}${PREFIX}/etc/spamdyke.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME}/documentation && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
