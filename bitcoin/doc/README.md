H2hcoin Core
=============

Setup
---------------------
H2hcoin Core is the original H2hcoin client and it builds the backbone of the network. It downloads and, by default, stores the entire history of H2hcoin transactions, which requires a few hundred gigabytes of disk space. Depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

To download H2hcoin Core, visit [h2hcoincore.org](https://h2hcoincore.org/en/download/).

Running
---------------------
The following are some helpful notes on how to run H2hcoin Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/h2hcoin-qt` (GUI) or
- `bin/h2hcoind` (headless)

### Windows

Unpack the files into a directory, and then run h2hcoin-qt.exe.

### macOS

Drag H2hcoin Core to your applications folder, and then run H2hcoin Core.

### Need Help?

* See the documentation at the [H2hcoin Wiki](https://en.h2hcoin.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#h2hcoin](http://webchat.freenode.net?channels=h2hcoin) on Freenode. If you don't have an IRC client, use [webchat here](http://webchat.freenode.net?channels=h2hcoin).
* Ask for help on the [H2hcoinTalk](https://h2hcointalk.org/) forums, in the [Technical Support board](https://h2hcointalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build H2hcoin Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [FreeBSD Build Notes](build-freebsd.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)
- [Gitian Building Guide (External Link)](https://github.com/h2hcoin-core/docs/blob/master/gitian-building.md)

Development
---------------------
The H2hcoin repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Productivity Notes](productivity.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/h2hcoin/doxygen/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [JSON-RPC Interface](JSON-RPC-interface.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Discuss on the [H2hcoinTalk](https://h2hcointalk.org/) forums, in the [Development & Technical Discussion board](https://h2hcointalk.org/index.php?board=6.0).
* Discuss project-specific development on #h2hcoin-core-dev on Freenode. If you don't have an IRC client, use [webchat here](http://webchat.freenode.net/?channels=h2hcoin-core-dev).
* Discuss general H2hcoin development on #h2hcoin-dev on Freenode. If you don't have an IRC client, use [webchat here](http://webchat.freenode.net/?channels=h2hcoin-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [h2hcoin.conf Configuration File](h2hcoin-conf.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)
- [PSBT support](psbt.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
