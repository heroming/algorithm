
/*
 * Author: momodi
 * Created Time:  2010/2/12 13:42:48
 * File Name: run.cpp
 * Description: 
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>

const int maxn = 256;

int main(int argc, char **argv) {
    char compiler[maxn] = {};
    sprintf(compiler, "javac %s.java", argv[1]);
    char runcommand[maxn] = {};
    sprintf(runcommand, "java %s", argv[1]);
    if (system(compiler) == 0) {
        int t = clock();
        if (system(runcommand) == 0) {
            printf("\nRun Time: %ldms\n", clock() - t);
        }
    }
    return 0;
}
