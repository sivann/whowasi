/* sivann 1995 */
/* Display your original uid/username after running in a suid shell.
 * Taken from the owner of controlling terminal. */

/* compile like this: 
 * gcc -O whowasi.c -o whowasi
 *  
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utmpx.h>
#include <pwd.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

main(ac, av)
  char           *av[];
  int             ac;
{
  char tty[64];
  char username[128],eusername[128];
  struct passwd * pwd;
  struct stat stat_s;

  if (ac == 2) {
    printf("%s, used to set the DISPLAY variable\n"
	   "Spiros Ioannou 1995\n", av[0]);
    exit(2);
  }

  strcpy(tty,ttyname(0));

  if (!*tty) {
    perror("ttyname");
    exit(1);
  }

  if (stat(tty,&stat_s)) {
    perror(tty);
    exit(2);
  }

  pwd=getpwuid(stat_s.st_uid); strcpy(username,pwd->pw_name);
  pwd=getpwuid(geteuid()); strcpy(eusername,pwd->pw_name);

  printf("uid:gid:username:eusername=%d:%d:%s:%s\n",
      stat_s.st_uid, stat_s.st_gid, username, eusername);
}
