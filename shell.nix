{ nixpkgs ? import <nixpkgs> {} }:
with nixpkgs;

mkShell {
  buildInputs = [
    haskellPackages.ghc
    haskellPackages.cabal-install
    arduino-cli
    pkgs.haskellPackages.stack
    pkgs.haskellPackages.haskell-language-server
  ];

  # Optional: Set environment variables
  shellHook = ''
    export PATH=$PATH:$HOME/.local/bin
  '';
}
