{
  description = "dev shell for dsa-in-cpp";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs =
    { nixpkgs, ... }:
    let
      forAllSystems = nixpkgs.lib.genAttrs [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ];
    in
    {
      devShells = forAllSystems (
        system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
        in
        {
          # gccStdenv uses g++ on macOS too (which is required).
          default = pkgs.mkShell.override { stdenv = pkgs.gccStdenv; } {
            packages = [
              pkgs.cmake
              pkgs.catch2_3
            ];
          };
        }
      );
    };
}
