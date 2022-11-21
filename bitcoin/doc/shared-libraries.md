Shared Libraries
================

## h2hcoinconsensus

The purpose of this library is to make the verification functionality that is critical to H2hcoin's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `h2hcoinconsensus.h` located in `src/script/h2hcoinconsensus.h`.

#### Version

`h2hcoinconsensus_version` returns an `unsigned int` with the API version *(currently `1`)*.

#### Script Validation

`h2hcoinconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `h2hcoinconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `h2hcoinconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `h2hcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/h2hcoin/bips/blob/master/bip-0016.mediawiki)) subscripts
- `h2hcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/h2hcoin/bips/blob/master/bip-0066.mediawiki)) compliance
- `h2hcoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/h2hcoin/bips/blob/master/bip-0147.mediawiki))
- `h2hcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/h2hcoin/bips/blob/master/bip-0065.mediawiki))
- `h2hcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/h2hcoin/bips/blob/master/bip-0112.mediawiki))
- `h2hcoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/h2hcoin/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `h2hcoinconsensus_ERR_OK` - No errors with input parameters *(see the return value of `h2hcoinconsensus_verify_script` for the verification status)*
- `h2hcoinconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `h2hcoinconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `h2hcoinconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `h2hcoinconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NH2hcoin](https://github.com/NicolasDorier/NH2hcoin/blob/master/NH2hcoin/Script.cs#L814) (.NET Bindings)
- [node-libh2hcoinconsensus](https://github.com/bitpay/node-libh2hcoinconsensus) (Node.js Bindings)
- [java-libh2hcoinconsensus](https://github.com/dexX7/java-libh2hcoinconsensus) (Java Bindings)
- [h2hcoinconsensus-php](https://github.com/Bit-Wasp/h2hcoinconsensus-php) (PHP Bindings)
