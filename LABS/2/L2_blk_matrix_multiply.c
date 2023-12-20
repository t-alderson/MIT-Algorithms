#include <stdio.h>
#include <time.h>

/* specify how many trials to repeat the experiment;
   the elapsed time for each trial will be measured separately */

#define NUM_TRIALS   3
#define N            1024
#define B            32

double a[N][N+1];
double b[N][N+1];
double c[N][N+1];


/* place other "#define" statements here for key parameters */


/* place your global variables (e.g., large arrays) here */


/* this calls a library routine to record the current time
   which will be the number of seconds and nanoseconds
   since 00:00:00 on January 1, 1970, Coordinated Universal Time
   (the name of this routine must be capital-T Time because
   there is a name conflict with some other symbol with lowercase-t) */

void Time (struct timespec *p)
{
  clock_gettime(CLOCK_REALTIME, p);
}

/* from two recorded times, compute and return the difference in seconds */

double TimeDiff (struct timespec *p0, struct timespec *p1)
{
  double t0, t1;

  /* the cast converts an integer to a double-precision floating-point value;
     there must be 9 zeros for the divisor because the units are nanoseconds */
  t0 = p0->tv_sec + ((double) p0->tv_nsec) / 1000000000;
  t1 = p1->tv_sec + ((double) p1->tv_nsec) / 1000000000;

  return t1 - t0;
}

/* place your data-initialization routine here */

void initialize_my_data (void)
{
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      a[i][j] = 0;
      b[i][j] = 0;
      c[i][j] = 0;
    }
  }
}

/* place the code for your algorithm of interest here */

void matrix_multiply (void)
{
  for(int ii = 0; ii < N; ii+=B){
    for(int jj = 0; jj < N; jj+=B){
      for(int i = ii; i < ii + B; i++){
        for(int j = jj; i < jj + B; i++){
          for(int k = 0; k < N; k++){
            c[i][j] = c[i][j] + a[j][k]*b[k][j];
          }       
        }
      }
    }
  }
}

/* main routine that performs multiple trials and reports the results */

int main(int argc, char *argv[])
{
  struct timespec start, finish;
  int i;
  double times[NUM_TRIALS]; /* this is a small array; use globals when large */
  double best, sum, avg;


  /* do one initial trial to: (a) allow the operating system to allocate all of the
     physical memory that will be needed, i.e., try to reduce the effect of such delays
     for later time measurements, and (b) ensure anything for time measurement and printing
     output is initialized; experiments showed that first timing and printing
     floating-point value was suprisingly long */

  initialize_my_data ();

  Time (&start);
  matrix_multiply();
  Time (&finish);
  printf ("\n");
  printf ("initialization run elapsed time = %g sec\n", TimeDiff (&start, &finish));
  printf ("\n");
  printf("Problem Size = %d\n", N);


  /* now perform the desired number of trials, each timed separately */

  for (i = 0; i < NUM_TRIALS; i++)
  {
    /* presuming that each trial starts with the same initial data
       so that algorithm behavior is the same each time */
    initialize_my_data();

    Time (&start);
    matrix_multiply();
    Time (&finish);

    /* record the time difference for this trial in array for later analysis */
    times[i] = TimeDiff (&start, &finish);

    /* this is _wall-clock_ time; includes any delays due to memory hierarchy
       and operating system moving the thread/process between processors */
    printf ("trial #%d elapsed time = %g sec\n", i+1, times[i]);
  }

  /* find the best (shortest) time, and compute the average for the trials */

  best = times[0];
  sum = 0.0;
  for (i = 0; i < NUM_TRIALS; i++)
  {
    if (times[i] < best)
      best = times[i];
    sum = sum + times[i];
  }
  avg = sum / NUM_TRIALS;

  printf ("\n");
  printf ("best time = %g sec\n", best);
  printf (" avg time = %g sec\n", avg);

  return 0;
}

