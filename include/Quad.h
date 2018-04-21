#ifndef INCLUDE_GUARD_0976DC5F6813412B9B48FB6C12277D8C
#define INCLUDE_GUARD_0976DC5F6813412B9B48FB6C12277D8C


///////////
// Types //
///////////

typedef enum Quad_Op_type {

	QUAD_OP_IDENTITY = 1,

	// Unary
	QUAD_OP_NEGATE,
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
	QUAD_OP_COPY_INDEXED_R,
	QUAD_OP_COPY_INDEXED_L,
	QUAD_OP_COPY_ADDRESS_R,
	QUAD_OP_COPY_DEREFED_R,
	QUAD_OP_COPY_DEREFED_L,


	// Labels and jumps
	QUAD_OP_LABEL,
	QUAD_OP_GOTO,
	QUAD_OP_GOTO_LT,
	QUAD_OP_GOTO_LE,
	QUAD_OP_GOTO_GT,
	QUAD_OP_GOTO_GE,
	QUAD_OP_GOTO_EQ,
	QUAD_OP_GOTO_NE,

	// Calls
	QUAD_OP_CALL,

	// IO
	QUAD_OP_READ_INT,
	QUAD_OP_READ_CHAR,
	QUAD_OP_WRITE_INT,
	QUAD_OP_WRITE_CHAR,

	QUAD_OP_UNKNOWN = -1,

} Quad_Op_type;

typedef enum Quad_AddrType_type{
	QUAD_ADDR_TYPE_EMPTY = 0,

	QUAD_ADDR_TYPE_NAME = 1,
	QUAD_ADDR_TYPE_REG,
	QUAD_ADDR_TYPE_CONSTANT,

	QUAD_ADDR_TYPE_UNKOWN = -1,
} Quad_AddrType_type;


////////////////
// Structures //
////////////////

typedef union Quad_Addr{
	void *name;
	int reg;
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
