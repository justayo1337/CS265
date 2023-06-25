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
