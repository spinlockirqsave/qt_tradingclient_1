/* 
 * File:   globals.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 18, 2013, 11:59 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H
/**
 * we should not define global variables in header files
 * we should define them in .c source files
 * this is why we only declare them as extern here
 * and initialize in main.cpp
 */
extern Repository marketDataRepository;

#define NUM_REPOTHREADS 20
extern pthread_mutex_t repoMutexes[NUM_REPOTHREADS];
extern pthread_cond_t repoConditions[NUM_REPOTHREADS];

#define macro_ibTickTypeToStdString(ibTickType) "\"" #ibTickType "\""

#endif	/* GLOBALS_H */

