with import <nixpkgs> {};
mkShell {
  nativeBuildInputs = [ cmake ];
  buildInputs = [ SDL2 ];

  packages = with pkgs; [
    clang-tools
  ];
}
