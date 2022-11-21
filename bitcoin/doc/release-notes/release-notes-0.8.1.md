H2hcoin-Qt/h2hcoind version 0.8.1 is now available from:
  http://sourceforge.net/projects/h2hcoin/files/H2hcoin/h2hcoin-0.8.1/

This is a maintenance release that adds a new network rule to avoid
a chain-forking incompatibility with versions 0.7.2 and earlier.

Please report bugs using the issue tracker at github:
  https://github.com/h2hcoin/h2hcoin/issues


How to Upgrade
--------------

If you are running an older version, shut it down. Wait
until it has completely shut down (which might take a few minutes for older
versions), then run the installer (on Windows) or just copy over
/Applications/H2hcoin-Qt (on Mac) or h2hcoind/h2hcoin-qt (on Linux).

If you are upgrading from version 0.7.2 or earlier, the first time you
run 0.8.1 your blockchain files will be re-indexed, which will take
anywhere from 30 minutes to several hours, depending on the speed of
your machine.
