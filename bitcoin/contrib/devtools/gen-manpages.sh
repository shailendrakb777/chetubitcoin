#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

H2HCOIND=${H2HCOIND:-$BINDIR/h2hcoind}
H2HCOINCLI=${H2HCOINCLI:-$BINDIR/h2hcoin-cli}
H2HCOINTX=${H2HCOINTX:-$BINDIR/h2hcoin-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/h2hcoin-wallet}
H2HCOINQT=${H2HCOINQT:-$BINDIR/qt/h2hcoin-qt}

[ ! -x $H2HCOIND ] && echo "$H2HCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($H2HCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for h2hcoind if --version-string is not set,
# but has different outcomes for h2hcoin-qt and h2hcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$H2HCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $H2HCOIND $H2HCOINCLI $H2HCOINTX $WALLET_TOOL $H2HCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
