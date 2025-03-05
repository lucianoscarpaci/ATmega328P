{ nixpkgs ? import <nixpkgs> {} }:
with nixpkgs;

mkShell {
  buildInputs = [
    haskellPackages.ghc
    haskellPackages.cabal-install
    arduino-cli
  ];
}