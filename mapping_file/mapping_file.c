#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>  
#include <fcntl.h>

int main (int argc, char **argv)
{
  if (!argc) {
    return -1;
  }
  const char *file_name = argv[1];
  // const char *pattern = argv[2];

  int fd = -1;
  fd = open(file_name, O_RDONLY);

  struct stat st;
  fstat(fd, &st);
  char *contents = (char*)mmap(NULL,
                        st.st_size,
                        PROT_READ,
                        MAP_SHARED,
                        fd, 0);

  printf("File contents: %s\n", contents);

  munmap(contents, st.st_size);
  close(fd);

  return 0;
}
