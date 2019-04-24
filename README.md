# arch_compare
C++ Program that compares the programs offered in Ubuntu repositories for two different architectures and lists the exclusive packages for each.

Requires local version of extracted Source.gz for both architectures (can be found at http://ports.ubuntu.com/ubuntu-ports/dists/bionic/main/ or http://security.ubuntu.com/ubuntu/dists/bionic/main/source/).

Make
  "make all"
  
Run
  "./supportTest [source1] [arch1] [source2] [arch2]"
  example "./supportTest sourceArm64 arm64 sourcex86 x86"
  example "./supportTest sourceArm64 arm64 sourcearmhf armhf"
  
View output
  open "arm64VSx86.txt" or "[arch1]VS[arch2].txt" with arch1 and arch1 being the third and fifth arguements passed to the program.
