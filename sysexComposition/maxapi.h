// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SoftstepSyxDemo_maxapi_h
#define SoftstepSyxDemo_maxapi_h


#define C74_CONST const



typedef enum {
	A_NOTHING = 0,	///< no type, thus no atom
	A_LONG,			///< long integer
	A_FLOAT,		///< 32-bit float
	A_SYM,			///< t_symbol pointer
	A_OBJ,			///< t_object pointer (for argtype lists; passes the value of sym)
	A_DEFLONG,		///< long but defaults to zero
	A_DEFFLOAT,		///< float, but defaults to zero
	A_DEFSYM,		///< symbol, defaults to ""
	A_GIMME,		///< request that args be passed as an array, the routine will check the types itself.
	A_CANT,			///< cannot typecheck args
	A_SEMI,			///< semicolon
	A_COMMA,		///< comma
	A_DOLLAR,		///< dollar
	A_DOLLSYM,		///< dollar
	A_GIMMEBACK,	///< request that args be passed as an array, the routine will check the types itself. can return atom value in final atom ptr arg. function returns long error code 0 = no err. see gimmeback_meth typedef
    
	A_DEFER	=		0x41,	///< A special signature for declaring methods. This is like A_GIMME, but the call is deferred.
	A_USURP =		0x42,	///< A special signature for declaring methods. This is like A_GIMME, but the call is deferred and multiple calls within one servicing of the queue are filtered down to one call.
	A_DEFER_LOW =	0x43,	///< A special signature for declaring methods. This is like A_GIMME, but the call is deferref to the back of the queue.
	A_USURP_LOW =	0x44	///< A special signature for declaring methods. This is like A_GIMME, but the call is deferred to the back of the queue and multiple calls within one servicing of the queue are filtered down to one call.
} e_max_atomtypes;


typedef float t_atom_float;			// the type that an A_FLOAT represents

/** Union for packing any of the datum defined in #e_max_atomtypes.
 @ingroup atom
 */
union word
{
	long w_long;			///< long integer
	t_atom_float w_float;	///< 32-bit float
//    char *s_name;
	struct symbol *w_sym;	///< pointer to a symbol in the Max symbol table
	struct object *w_obj;	///< pointer to a #t_object or other generic pointer
};


/** An atom is a typed datum.
 @ingroup atom
 */
typedef struct atom
{
	short a_type;			///< a value as defined in #e_max_atomtypes
	union word a_w;			///< the actual data
} Atom, t_atom;



typedef struct symbol
{
	char *s_name;			///< name: a c-string
	struct object *s_thing;	///< possible binding to a t_object
} Symbol, t_symbol;

typedef void *(*method)(void *, ...);

#define MAXARG 7

typedef struct messlist
{
	struct symbol *m_sym;		///< Name of the message
	method m_fun;				///< Method associated with the message
	char m_type[MAXARG + 1];	///< Argument type information
} Messlist, t_messlist;


typedef struct object
{
	struct messlist *o_messlist;	///<  list of messages and methods. The -1 entry of the message list of an object contains a pointer to its #t_class entry.
    // (also used as freelist link)
#ifdef CAREFUL
	long o_magic;					///< magic number
#endif
	struct inlet *o_inlet;			///<  list of inlets
	struct outlet *o_outlet;		///<  list of outlets
} Object, t_object;



typedef struct maxclass
{
	struct symbol *c_sym;			///< symbol giving name of class
	struct object **c_freelist;		// linked list of free ones
	method c_freefun;				// function to call when freeing
	short c_size;					// size of an instance
	char c_tiny;					// flag indicating tiny header
	char c_noinlet;					// flag indicating no first inlet for patcher
	struct symbol *c_filename;		///< name of file associated with this class
	t_messlist *c_newmess;			// constructor method/type information
	method c_menufun;				// function to call when creating from object pallette (default constructor)
	long c_flags;					// class flags used to determine context in which class may be used
	long c_messcount;				// size of messlist array
	t_messlist *c_messlist;			// messlist arrray
	void *c_attributes;				// t_hashtab object
	void *c_extra;					// t_hashtab object
	long c_obexoffset;				// if non zero, object struct contains obex pointer at specified byte offset
} Maxclass, t_class;


void maxapi_init(void);
#define post    printf
//void post(C74_CONST char *fmt, ...);
t_symbol *gensym(char *s);
void *outlet_anything(void *o, t_symbol *s, short ac, t_atom *av);



#endif
