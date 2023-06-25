/********************************************************************************
 * stack-arr.c -- implementation for stack functions (built over an array)
 *
 * Kurt Schmidt
 * NOV 2020
 *
 * gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0, on
 * GNU/Linux 4.15.0-117-generic x86_64
 *
 * EDITOR:  tabstop=2, cols=120
 *
 ********************************************************************************/

#include <assert.h>
#include <stdlib.h>

#include "stack.h"


const size_t INIT_SIZE = 2 ;


struct stack_arr
{
	ELEM *arr ;		// to point to heap array
	size_t size ;		// # number of elements (size of stack)
	size_t cap ;			// capacity
} ;


stack* mkStack()
{
	stack *rv = (stack*) malloc( sizeof( stack )) ;
	assert( rv != NULL ) ;

	rv->arr = (ELEM*) malloc( INIT_SIZE * sizeof( ELEM )) ;
	rv->size = 0 ;
	rv->cap = INIT_SIZE ;
}

_Bool isEmpty( const stack* s ) 
{
	return s->size == 0 ;
}

void stackResize( stack *s, size_t new_size )
{
	ELEM *t = malloc( new_size * sizeof( ELEM )) ;
	if( t==NULL )
		return ;

		// in case new_size is smaller
	size_t size = s->size < new_size ? s->size : new_size ;

	for( size_t i=0; i<size; ++i )
		t[i] = s->arr[i] ;
	
	free( s->arr ) ;
	s->arr = t ;
	s->cap = new_size ;
	if( s->size > s->cap )
		s->size = s->cap ;
	t = NULL ;  // not needed, going out of scope

	return ;
}

void push( stack* s, ELEM i ) 
{
	if( s->size >= s->cap ) 
		stackResize( s, 2*s->size ) ;  // get new array, double the size

	s->arr[ s->size ] = i ;
	s->size += 1 ;
}

ELEM pop( stack* s ) 
{
	assert( s->size > 0 ) ;
	s->size -= 1 ;
	return s->arr[ s->size ] ;
}

ELEM top( const stack* s ) 
{
	assert( s->size > 0 ) ;
	ELEM rv = s->arr[ s->size-1 ] ;

	return rv ;
}

