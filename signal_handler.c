#include "shell.h"

/**
  * signal_handler - handler of signals
  * @sig_id: the identifier of the signal to handle
  *
  * Return: void
*/
void signal_handler(int sig_id)
{
if (sig_id == SIGINT)
write(STDOUT_FILENO, "\n($) ", 5);
}