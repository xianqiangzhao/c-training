// gcc xxx.c -lcrypt  -o xxx
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

int
main(void)
{
  /* Hashed form of "GNU libc manual". */
  const char *const pass = "$1$/iSaq7rB$MQsoQ00dQcu5NcOeSvV9f1";

  char *result;
  int ok;

  //pass is abcd
  result = crypt(getpass("Password:"), pass);
   /* Test the result. */
  ok = strcmp (result, pass) == 0;

  puts(ok ? "Access granted." : "Access denied.");
  return ok ? 0 : 1;
}