# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	mac_nonet
DISTVERSION=	g20150821
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-kmod

MAINTAINER=	amutu@amutu.com
COMMENT=	MAC policy to disable access to networking for certain group

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to build: make[1]: don't know how to make /usr/src/sys/tools/vnode_if.awk

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	pbiernacki
GH_TAGNAME=	f7e008a

PLIST_FILES=	${KMODDIR}/mac_nonet.ko

.include <bsd.port.mk>
