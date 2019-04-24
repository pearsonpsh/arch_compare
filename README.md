# arch_compare
C++ Program that compares the programs offered in Ubuntu repositories for two different architectures and lists the exclusive packages for each.

Requires local version of extracted Sources.gz for both architectures (can be found at http://ports.ubuntu.com/ubuntu-ports/dists/bionic/main/ or http://security.ubuntu.com/ubuntu/dists/bionic/main/source/) and extracted and named so you can tell them apart in the same folder as the project.

Download
  Move to where you want to clone the project
  "git clone github.com/pearsonpsh/arch_compare/"


Make

  "make all"


Run

  "./supportTest [source1] [arch1] [source2] [arch2]"
  
  ex1 "./supportTest sourcesArm64 arm64 sourcesx86 x86"
  
  ex2 "./supportTest sourcesArm64 arm64 sourcesarmhf armhf"


View output

open "arm64VSx86.txt" or "[arch1]VS[arch2].txt" with arch1 and arch1 being the third and fifth arguements passed to the program.
