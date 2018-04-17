#ifndef INCLUDE_GUARD_0976DC5F6813412B9B48FB6C12277D8C
#define INCLUDE_GUARD_0976DC5F6813412B9B48FB6C12277D8C


///////////
// Types //
///////////

typedef enum Quad_Op_type {
	// Unary
	QUAD_OP_NEGATE = 1,
	QUAD_OP_NOT,

	// Binary arith
	QUAD_OP_ADD,
	QUAD_OP_SUBTRACT,
	QUAD_OP_MULTIPLY,
	QUAD_OP_DIVIDE,
	QUAD_OP_AND,
	QUAD_OP_OR,


	// Copy
	QUAD_OP_COPY,
	QUAD_OP_COPY_INDEX_R,
	QUAD_OP_COPY_INDEX_L,
	QUAD_OP_COPY_ADDRESS_R,
	QUAD_OP_COPY_DEREF_R,
	QUAD_OP_COPY_DEREF_L,


	// Jump
	QUAD_OP_JUMP,
	QUAD_OP_JUMP_TRUE,
	QUAD_OP_JUMP_FALSE,
	QUAD_OP_JUMP_LT,
	QUAD_OP_JUMP_LE,
	QUAD_OP_JUMP_GT,
	QUAD_OP_JUMP_GE,
	QUAD_OP_JUMP_EQ,
	QUAD_OP_JUMP_NE,

	// Calls
	// Not implemented!

	QUAD_OP_UNKNOWN = -1,

} Quad_Op_type;

typedef enum Quad_AddrType_type{
	QUAD_ADDR_TYPE_EMPTY = 0,

	QUAD_ADDR_TYPE_NAME = 1,
	QUAD_ADDR_TYPE_TEMP,
	QUAD_ADDR_TYPE_CONSTANT,

	QUAD_ADDR_TYPE_UNKOWN = -1,
} Quad_AddrType_type;


////////////////
// Structures //
////////////////

typedef union Quad_Addr{
	void *name;
	void *temp;
	long long constant;
} Quad_Addr;

typedef struct Quad_Node Quad_Node;

typedef struct Quad_Node{
	Quad_Op_type op;

	Quad_AddrType_type arg_1_type;
	Quad_AddrType_type arg_2_type;
	Quad_AddrType_type result_type;

	Quad_Addr arg_1;
	Quad_Addr arg_2;
	Quad_Addr result;

	Quad_Node *next;
	Quad_Node *previous;
} Quad_Node;


////////////////////////////////
// Constructors & destructors //
////////////////////////////////


Quad_Node *Quad_Node_new();

void Quad_Node_destroy(Quad_Node *quad_ptr);


#endif
