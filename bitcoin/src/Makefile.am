# Copyright (c) 2013-2016 The H2hcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

DIST_SUBDIRS = secp256k1 univalue

AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS) $(GPROF_LDFLAGS) $(SANITIZER_LDFLAGS)
AM_CXXFLAGS = $(DEBUG_CXXFLAGS) $(HARDENED_CXXFLAGS) $(WARN_CXXFLAGS) $(NOWARN_CXXFLAGS) $(ERROR_CXXFLAGS) $(GPROF_CXXFLAGS) $(SANITIZER_CXXFLAGS)
AM_CPPFLAGS = $(DEBUG_CPPFLAGS) $(HARDENED_CPPFLAGS)
AM_LIBTOOLFLAGS = --preserve-dup-deps
EXTRA_LIBRARIES =

if EMBEDDED_UNIVALUE
LIBUNIVALUE = univalue/libunivalue.la

$(LIBUNIVALUE): $(wildcard univalue/lib/*) $(wildcard univalue/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
else
LIBUNIVALUE = $(UNIVALUE_LIBS)
endif

H2HCOIN_INCLUDES=-I$(builddir) $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

H2HCOIN_INCLUDES += -I$(srcdir)/secp256k1/include
H2HCOIN_INCLUDES += $(UNIVALUE_CFLAGS)

LIBH2HCOIN_SERVER=libh2hcoin_server.a
LIBH2HCOIN_COMMON=libh2hcoin_common.a
LIBH2HCOIN_CONSENSUS=libh2hcoin_consensus.a
LIBH2HCOIN_CLI=libh2hcoin_cli.a
LIBH2HCOIN_UTIL=libh2hcoin_util.a
LIBH2HCOIN_CRYPTO_BASE=crypto/libh2hcoin_crypto_base.a
LIBH2HCOINQT=qt/libh2hcoinqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

if ENABLE_ZMQ
LIBH2HCOIN_ZMQ=libh2hcoin_zmq.a
endif
if BUILD_H2HCOIN_LIBS
LIBH2HCOINCONSENSUS=libh2hcoinconsensus.la
endif
if ENABLE_WALLET
LIBH2HCOIN_WALLET=libh2hcoin_wallet.a
LIBH2HCOIN_WALLET_TOOL=libh2hcoin_wallet_tool.a
endif

LIBH2HCOIN_CRYPTO= $(LIBH2HCOIN_CRYPTO_BASE)
if ENABLE_SSE41
LIBH2HCOIN_CRYPTO_SSE41 = crypto/libh2hcoin_crypto_sse41.a
LIBH2HCOIN_CRYPTO += $(LIBH2HCOIN_CRYPTO_SSE41)
endif
if ENABLE_AVX2
LIBH2HCOIN_CRYPTO_AVX2 = crypto/libh2hcoin_crypto_avx2.a
LIBH2HCOIN_CRYPTO += $(LIBH2HCOIN_CRYPTO_AVX2)
endif
if ENABLE_SHANI
LIBH2HCOIN_CRYPTO_SHANI = crypto/libh2hcoin_crypto_shani.a
LIBH2HCOIN_CRYPTO += $(LIBH2HCOIN_CRYPTO_SHANI)
endif

$(LIBSECP256K1): $(wildcard secp256k1/src/*.h) $(wildcard secp256k1/src/*.c) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES += \
  $(LIBH2HCOIN_CRYPTO) \
  $(LIBH2HCOIN_UTIL) \
  $(LIBH2HCOIN_COMMON) \
  $(LIBH2HCOIN_CONSENSUS) \
  $(LIBH2HCOIN_SERVER) \
  $(LIBH2HCOIN_CLI) \
  $(LIBH2HCOIN_WALLET) \
  $(LIBH2HCOIN_WALLET_TOOL) \
  $(LIBH2HCOIN_ZMQ)

lib_LTLIBRARIES = $(LIBH2HCOINCONSENSUS)

bin_PROGRAMS =
noinst_PROGRAMS =
TESTS =
BENCHMARKS =

if BUILD_H2HCOIND
  bin_PROGRAMS += h2hcoind
endif

if BUILD_H2HCOIN_CLI
  bin_PROGRAMS += h2hcoin-cli
endif
if BUILD_H2HCOIN_TX
  bin_PROGRAMS += h2hcoin-tx
endif
if ENABLE_WALLET
if BUILD_H2HCOIN_WALLET
  bin_PROGRAMS += h2hcoin-wallet
endif
endif

.PHONY: FORCE check-symbols check-security
# h2hcoin core #
H2HCOIN_CORE_H = \
  addrdb.h \
  addrman.h \
  attributes.h \
  banman.h \
  base58.h \
  bech32.h \
  bloom.h \
  blockencodings.h \
  blockfilter.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coins.h \
  compat.h \
  compat/assumptions.h \
  compat/byteswap.h \
  compat/endian.h \
  compat/sanity.h \
  compressor.h \
  consensus/consensus.h \
  consensus/tx_check.h \
  consensus/tx_verify.h \
  core_io.h \
  core_memusage.h \
  cuckoocache.h \
  flatfile.h \
  fs.h \
  httprpc.h \
  httpserver.h \
  index/base.h \
  index/txindex.h \
  indirectmap.h \
  init.h \
  interfaces/chain.h \
  interfaces/handler.h \
  interfaces/node.h \
  interfaces/wallet.h \
  key.h \
  key_io.h \
  keystore.h \
  dbwrapper.h \
  limitedmap.h \
  logging.h \
  memusage.h \
  merkleblock.h \
  miner.h \
  net.h \
  net_processing.h \
  netaddress.h \
  netbase.h \
  netmessagemaker.h \
  node/coin.h \
  node/psbt.h \
  node/transaction.h \
  noui.h \
  optional.h \
  outputtype.h \
  policy/feerate.h \
  policy/fees.h \
  policy/policy.h \
  policy/rbf.h \
  policy/settings.h \
  pow.h \
  protocol.h \
  psbt.h \
  random.h \
  reverse_iterator.h \
  reverselock.h \
  rpc/blockchain.h \
  rpc/client.h \
  rpc/mining.h \
  rpc/protocol.h \
  rpc/server.h \
  rpc/rawtransaction_util.h \
  rpc/register.h \
  rpc/util.h \
  scheduler.h \
  script/descriptor.h \
  script/ismine.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  shutdown.h \
  streams.h \
  support/allocators/secure.h \
  support/allocators/zeroafterfree.h \
  support/cleanse.h \
  support/events.h \
  support/lockedpool.h \
  sync.h \
  threadsafety.h \
  threadinterrupt.h \
  timedata.h \
  torcontrol.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  undo.h \
  util/bip32.h \
  util/bytevectorhash.h \
  util/error.h \
  util/fees.h \
  util/system.h \
  util/memory.h \
  util/moneystr.h \
  util/rbf.h \
  util/time.h \
  util/url.h \
  util/validation.h \
  validation.h \
  validationinterface.h \
  versionbits.h \
  versionbitsinfo.h \
  walletinitinterface.h \
  wallet/coincontrol.h \
  wallet/crypter.h \
  wallet/db.h \
  wallet/feebumper.h \
  wallet/fees.h \
  wallet/load.h \
  wallet/psbtwallet.h \
  wallet/rpcwallet.h \
  wallet/wallet.h \
  wallet/walletdb.h \
  wallet/wallettool.h \
  wallet/walletutil.h \
  wallet/coinselection.h \
  warnings.h \
  zmq/zmqabstractnotifier.h \
  zmq/zmqconfig.h\
  zmq/zmqnotificationinterface.h \
  zmq/zmqpublishnotifier.h \
  zmq/zmqrpc.h


obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh "$(abs_top_builddir)/src/obj/build.h" \
	  "$(abs_top_srcdir)"
libh2hcoin_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between h2hcoind and h2hcoin-qt
# Contains code accessing mempool and chain state that is meant to be separated
# from wallet and gui code (see node/README.md). Shared code should go in
# libh2hcoin_common or libh2hcoin_util libraries, instead.
libh2hcoin_server_a_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
libh2hcoin_server_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libh2hcoin_server_a_SOURCES = \
  addrdb.cpp \
  addrman.cpp \
  banman.cpp \
  blockencodings.cpp \
  blockfilter.cpp \
  chain.cpp \
  checkpoints.cpp \
  consensus/tx_verify.cpp \
  flatfile.cpp \
  httprpc.cpp \
  httpserver.cpp \
  index/base.cpp \
  index/txindex.cpp \
  interfaces/chain.cpp \
  interfaces/node.cpp \
  init.cpp \
  dbwrapper.cpp \
  miner.cpp \
  net.cpp \
  net_processing.cpp \
  node/coin.cpp \
  node/psbt.cpp \
  node/transaction.cpp \
  noui.cpp \
  policy/fees.cpp \
  policy/rbf.cpp \
  policy/settings.cpp \
  pow.cpp \
  rest.cpp \
  rpc/blockchain.cpp \
  rpc/mining.cpp \
  rpc/misc.cpp \
  rpc/net.cpp \
  rpc/rawtransaction.cpp \
  rpc/server.cpp \
  script/sigcache.cpp \
  shutdown.cpp \
  timedata.cpp \
  torcontrol.cpp \
  txdb.cpp \
  txmempool.cpp \
  ui_interface.cpp \
  validation.cpp \
  validationinterface.cpp \
  versionbits.cpp \
  $(H2HCOIN_CORE_H)

if ENABLE_WALLET
libh2hcoin_server_a_SOURCES += wallet/init.cpp
endif
if !ENABLE_WALLET
libh2hcoin_server_a_SOURCES += dummywallet.cpp
endif

if ENABLE_ZMQ
libh2hcoin_zmq_a_CPPFLAGS = $(H2HCOIN_INCLUDES) $(ZMQ_CFLAGS)
libh2hcoin_zmq_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libh2hcoin_zmq_a_SOURCES = \
  zmq/zmqabstractnotifier.cpp \
  zmq/zmqnotificationinterface.cpp \
  zmq/zmqpublishnotifier.cpp \
  zmq/zmqrpc.cpp
endif


# wallet: shared between h2hcoind and h2hcoin-qt, but only linked
# when wallet enabled
libh2hcoin_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES)
libh2hcoin_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libh2hcoin_wallet_a_SOURCES = \
  interfaces/wallet.cpp \
  wallet/coincontrol.cpp \
  wallet/crypter.cpp \
  wallet/db.cpp \
  wallet/feebumper.cpp \
  wallet/fees.cpp \
  wallet/load.cpp \
  wallet/psbtwallet.cpp \
  wallet/rpcdump.cpp \
  wallet/rpcwallet.cpp \
  wallet/wallet.cpp \
  wallet/walletdb.cpp \
  wallet/walletutil.cpp \
  wallet/coinselection.cpp \
  $(H2HCOIN_CORE_H)

libh2hcoin_wallet_tool_a_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES)
libh2hcoin_wallet_tool_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libh2hcoin_wallet_tool_a_SOURCES = \
  wallet/wallettool.cpp \
  $(H2HCOIN_CORE_H)

# crypto primitives library
crypto_libh2hcoin_crypto_base_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libh2hcoin_crypto_base_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libh2hcoin_crypto_base_a_SOURCES = \
  crypto/aes.cpp \
  crypto/aes.h \
  crypto/chacha20.h \
  crypto/chacha20.cpp \
  crypto/common.h \
  crypto/hmac_sha256.cpp \
  crypto/hmac_sha256.h \
  crypto/hmac_sha512.cpp \
  crypto/hmac_sha512.h \
  crypto/poly1305.h \
  crypto/poly1305.cpp \
  crypto/ripemd160.cpp \
  crypto/ripemd160.h \
  crypto/sha1.cpp \
  crypto/sha1.h \
  crypto/sha256.cpp \
  crypto/sha256.h \
  crypto/sha512.cpp \
  crypto/sha512.h \
  crypto/siphash.cpp \
  crypto/siphash.h

if USE_ASM
crypto_libh2hcoin_crypto_base_a_SOURCES += crypto/sha256_sse4.cpp
endif

crypto_libh2hcoin_crypto_sse41_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libh2hcoin_crypto_sse41_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libh2hcoin_crypto_sse41_a_CXXFLAGS += $(SSE41_CXXFLAGS)
crypto_libh2hcoin_crypto_sse41_a_CPPFLAGS += -DENABLE_SSE41
crypto_libh2hcoin_crypto_sse41_a_SOURCES = crypto/sha256_sse41.cpp

crypto_libh2hcoin_crypto_avx2_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libh2hcoin_crypto_avx2_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libh2hcoin_crypto_avx2_a_CXXFLAGS += $(AVX2_CXXFLAGS)
crypto_libh2hcoin_crypto_avx2_a_CPPFLAGS += -DENABLE_AVX2
crypto_libh2hcoin_crypto_avx2_a_SOURCES = crypto/sha256_avx2.cpp

crypto_libh2hcoin_crypto_shani_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libh2hcoin_crypto_shani_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libh2hcoin_crypto_shani_a_CXXFLAGS += $(SHANI_CXXFLAGS)
crypto_libh2hcoin_crypto_shani_a_CPPFLAGS += -DENABLE_SHANI
crypto_libh2hcoin_crypto_shani_a_SOURCES = crypto/sha256_shani.cpp

# consensus: shared between all executables that validate any consensus rules.
libh2hcoin_consensus_a_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES)
libh2hcoin_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libh2hcoin_consensus_a_SOURCES = \
  amount.h \
  arith_uint256.cpp \
  arith_uint256.h \
  consensus/merkle.cpp \
  consensus/merkle.h \
  consensus/params.h \
  consensus/tx_check.cpp \
  consensus/validation.h \
  hash.cpp \
  hash.h \
  prevector.h \
  primitives/block.cpp \
  primitives/block.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  script/h2hcoinconsensus.cpp \
  script/interpreter.cpp \
  script/interpreter.h \
  script/script.cpp \
  script/script.h \
  script/script_error.cpp \
  script/script_error.h \
  serialize.h \
  span.h \
  tinyformat.h \
  uint256.cpp \
  uint256.h \
  util/strencodings.cpp \
  util/strencodings.h \
  version.h

# common: shared between h2hcoind, and h2hcoin-qt and non-server tools
libh2hcoin_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES)
libh2hcoin_common_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libh2hcoin_common_a_SOURCES = \
  base58.cpp \
  bech32.cpp \
  bloom.cpp \
  chainparams.cpp \
  coins.cpp \
  compressor.cpp \
  core_read.cpp \
  core_write.cpp \
  key.cpp \
  key_io.cpp \
  keystore.cpp \
  merkleblock.cpp \
  netaddress.cpp \
  netbase.cpp \
  outputtype.cpp \
  policy/feerate.cpp \
  policy/policy.cpp \
  protocol.cpp \
  psbt.cpp \
  rpc/rawtransaction_util.cpp \
  rpc/util.cpp \
  scheduler.cpp \
  script/descriptor.cpp \
  script/ismine.cpp \
  script/sign.cpp \
  script/standard.cpp \
  versionbitsinfo.cpp \
  warnings.cpp \
  $(H2HCOIN_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libh2hcoin_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES)
libh2hcoin_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libh2hcoin_util_a_SOURCES = \
  support/lockedpool.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  fs.cpp \
  interfaces/handler.cpp \
  logging.cpp \
  random.cpp \
  rpc/protocol.cpp \
  support/cleanse.cpp \
  sync.cpp \
  threadinterrupt.cpp \
  util/bip32.cpp \
  util/bytevectorhash.cpp \
  util/error.cpp \
  util/fees.cpp \
  util/system.cpp \
  util/moneystr.cpp \
  util/rbf.cpp \
  util/strencodings.cpp \
  util/time.cpp \
  util/url.cpp \
  util/validation.cpp \
  $(H2HCOIN_CORE_H)

if GLIBC_BACK_COMPAT
libh2hcoin_util_a_SOURCES += compat/glibc_compat.cpp
AM_LDFLAGS += $(COMPAT_LDFLAGS)
endif

# cli: shared between h2hcoin-cli and h2hcoin-qt
libh2hcoin_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES)
libh2hcoin_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libh2hcoin_cli_a_SOURCES = \
  rpc/client.cpp \
  $(H2HCOIN_CORE_H)

nodist_libh2hcoin_util_a_SOURCES = $(srcdir)/obj/build.h
#

# h2hcoind binary #
h2hcoind_SOURCES = h2hcoind.cpp
h2hcoind_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES)
h2hcoind_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
h2hcoind_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
h2hcoind_SOURCES += h2hcoind-res.rc
endif

# Libraries below may be listed more than once to resolve circular dependencies (see
# https://eli.thegreenplace.net/2013/07/09/library-order-in-static-linking#circular-dependency)
h2hcoind_LDADD = \
  $(LIBH2HCOIN_SERVER) \
  $(LIBH2HCOIN_WALLET) \
  $(LIBH2HCOIN_SERVER) \
  $(LIBH2HCOIN_COMMON) \
  $(LIBUNIVALUE) \
  $(LIBH2HCOIN_UTIL) \
  $(LIBH2HCOIN_ZMQ) \
  $(LIBH2HCOIN_CONSENSUS) \
  $(LIBH2HCOIN_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

h2hcoind_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(ZMQ_LIBS)

# h2hcoin-cli binary #
h2hcoin_cli_SOURCES = h2hcoin-cli.cpp
h2hcoin_cli_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES) $(EVENT_CFLAGS)
h2hcoin_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
h2hcoin_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
h2hcoin_cli_SOURCES += h2hcoin-cli-res.rc
endif

h2hcoin_cli_LDADD = \
  $(LIBH2HCOIN_CLI) \
  $(LIBUNIVALUE) \
  $(LIBH2HCOIN_UTIL) \
  $(LIBH2HCOIN_CRYPTO)

h2hcoin_cli_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS) $(EVENT_LIBS)
#

# h2hcoin-tx binary #
h2hcoin_tx_SOURCES = h2hcoin-tx.cpp
h2hcoin_tx_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES)
h2hcoin_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
h2hcoin_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
h2hcoin_tx_SOURCES += h2hcoin-tx-res.rc
endif

h2hcoin_tx_LDADD = \
  $(LIBUNIVALUE) \
  $(LIBH2HCOIN_COMMON) \
  $(LIBH2HCOIN_UTIL) \
  $(LIBH2HCOIN_CONSENSUS) \
  $(LIBH2HCOIN_CRYPTO) \
  $(LIBSECP256K1)

h2hcoin_tx_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS)
#

# h2hcoin-wallet binary #
h2hcoin_wallet_SOURCES = h2hcoin-wallet.cpp
h2hcoin_wallet_CPPFLAGS = $(AM_CPPFLAGS) $(H2HCOIN_INCLUDES)
h2hcoin_wallet_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
h2hcoin_wallet_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
h2hcoin_wallet_SOURCES += h2hcoin-wallet-res.rc
endif

h2hcoin_wallet_LDADD = \
  $(LIBH2HCOIN_WALLET_TOOL) \
  $(LIBH2HCOIN_WALLET) \
  $(LIBH2HCOIN_COMMON) \
  $(LIBH2HCOIN_CONSENSUS) \
  $(LIBH2HCOIN_UTIL) \
  $(LIBH2HCOIN_CRYPTO) \
  $(LIBH2HCOIN_ZMQ) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1) \
  $(LIBUNIVALUE)

h2hcoin_wallet_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(CRYPTO_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(MINIUPNPC_LIBS) $(ZMQ_LIBS)
#

# h2hcoinconsensus library #
if BUILD_H2HCOIN_LIBS
include_HEADERS = script/h2hcoinconsensus.h
libh2hcoinconsensus_la_SOURCES = $(crypto_libh2hcoin_crypto_base_a_SOURCES) $(libh2hcoin_consensus_a_SOURCES)

if GLIBC_BACK_COMPAT
  libh2hcoinconsensus_la_SOURCES += compat/glibc_compat.cpp
endif

libh2hcoinconsensus_la_LDFLAGS = $(AM_LDFLAGS) -no-undefined $(RELDFLAGS)
libh2hcoinconsensus_la_LIBADD = $(LIBSECP256K1)
libh2hcoinconsensus_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_H2HCOIN_INTERNAL
libh2hcoinconsensus_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#

CTAES_DIST =  crypto/ctaes/bench.c
CTAES_DIST += crypto/ctaes/ctaes.c
CTAES_DIST += crypto/ctaes/ctaes.h
CTAES_DIST += crypto/ctaes/README.md
CTAES_DIST += crypto/ctaes/test.c

CLEANFILES = $(EXTRA_LIBRARIES)

CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno
CLEANFILES += zmq/*.gcda zmq/*.gcno
CLEANFILES += obj/build.h

EXTRA_DIST = $(CTAES_DIST)


config/h2hcoin-config.h: config/stamp-h1
	@$(MAKE) -C $(top_builddir) $(subdir)/$(@)
config/stamp-h1: $(top_srcdir)/$(subdir)/config/h2hcoin-config.h.in $(top_builddir)/config.status
	$(AM_V_at)$(MAKE) -C $(top_builddir) $(subdir)/$(@)
$(top_srcdir)/$(subdir)/config/h2hcoin-config.h.in:  $(am__configure_deps)
	$(AM_V_at)$(MAKE) -C $(top_srcdir) $(subdir)/config/h2hcoin-config.h.in

clean-local:
	-$(MAKE) -C secp256k1 clean
	-$(MAKE) -C univalue clean
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -f config.h
	-rm -rf test/__pycache__

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@

check-symbols: $(bin_PROGRAMS)
if GLIBC_BACK_COMPAT
	@echo "Checking glibc back compat..."
	$(AM_V_at) READELF=$(READELF) CPPFILT=$(CPPFILT) $(PYTHON) $(top_srcdir)/contrib/devtools/symbol-check.py < $(bin_PROGRAMS)
endif

check-security: $(bin_PROGRAMS)
if HARDEN
	@echo "Checking binary security..."
	$(AM_V_at) READELF=$(READELF) OBJDUMP=$(OBJDUMP) $(PYTHON) $(top_srcdir)/contrib/devtools/security-check.py < $(bin_PROGRAMS)
endif

if ENABLE_BIP70
%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(<D) $<
endif

if EMBEDDED_LEVELDB
include Makefile.leveldb.include
endif

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_BENCH
include Makefile.bench.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
