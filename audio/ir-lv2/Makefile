# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	ir
DISTVERSION=	1.3.3-2
DISTVERSIONSUFFIX=	-gb94bc67
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 impulse response plugin for reverb and cabinet simulation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate \
		libzita-convolver.so:audio/zita-convolver \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	tomszilagyi
GH_PROJECT=	ir.lv2
USE_GNOME=	glib20 gtk20 gdkpixbuf2 cairo

PLIST_FILES=	lib/lv2/ir.lv2/ir.so lib/lv2/ir.lv2/ir.ttl \
		lib/lv2/ir.lv2/ir_gui.so lib/lv2/ir.lv2/manifest.ttl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/ir.lv2/*.so

.include <bsd.port.mk>
