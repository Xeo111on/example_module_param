#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GLEB KOROBEYNIKOV");

static int int_param = 0;
module_param( int_param, int, 0);

static int k = 0;
module_param_named( name_param, k, int, 0);

static bool var_b = true;
module_param_named( bool_var, var_b, invbool,0);
				//module_param( var_b, invbool/bool , 0);

static char *param;
module_param( param, charp, 0);

#define MAXLEN 10
static char str[ MAXLEN ] = "";
module_param_string( cparam, str, sizeof( str ), 0);

#define MAX_SIZE_ARRAY 10
static int a[ MAX_SIZE_ARRAY ] = { 0 };
static int asize = sizeof( a ) / sizeof( a[ 0 ] );
module_param_array( a, int, &asize, S_IRUGO | S_IWUSR );

static int __init module_load( void )
{
	int j;
	char buff_msg[ 40 ];
	printk("=========================\n");
	printk("int_param = %d\n", int_param);
	printk("name_param = %d\n", k);
	printk("bool_var = %d\n", var_b);
	printk("param = %s\n", param);
	printk("cparam = %s { %zu }\n", str, strlen( str ));
	
	for( j=0; j < asize; j++)
	{
		sprintf( ( buff_msg + j ), "%d", a[ j ] );
	}

	printk("%s\n", buff_msg );
	printk("=========================\n");
	return -1;
}

module_init( module_load );
