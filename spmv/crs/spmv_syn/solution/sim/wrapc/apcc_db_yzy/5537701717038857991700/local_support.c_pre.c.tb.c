/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC_bench_args_t l_struct_OC_bench_args_t;

/* Structure contents */
struct l_struct_OC_bench_args_t {
  double field0[1666];
  signed int field1[1666];
  signed int field2[495];
  double field3[494];
  double field4[494];
};


/* External Global Variable Declarations */
extern unsigned int INPUT_SIZE;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void run_benchmark( char *llvm_cbe_vargs);
void apatb_spmv_sw(double *, signed int *, signed int *, double *, double *);
void input_to_data(signed int llvm_cbe_fd,  char *llvm_cbe_vdata);
 char *readfile(signed int );
 char *find_section_start( char *, signed int );
signed int parse_double_array( char *, double *, signed int );
signed int parse_int32_t_array( char *, signed int *, signed int );
void data_to_input(signed int llvm_cbe_fd,  char *llvm_cbe_vdata);
signed int write_section_header(signed int );
signed int write_double_array(signed int , double *, signed int );
signed int write_int32_t_array(signed int , signed int *, signed int );
void output_to_data(signed int llvm_cbe_fd,  char *llvm_cbe_vdata);
void data_to_output(signed int llvm_cbe_fd,  char *llvm_cbe_vdata);
signed int check_data( char *llvm_cbe_vdata,  char *llvm_cbe_vref);


/* Global Variable Definitions and Initialization */
unsigned int INPUT_SIZE = 29880u;


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void run_benchmark( char *llvm_cbe_vargs) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  l_struct_OC_bench_args_t *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  double *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  signed int *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  signed int *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  double *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  double *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @run_benchmark\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8* %%vargs to %%struct.bench_args_t*, !dbg !5 for 0x%llxth hint within @run_benchmark  --> \n", ++aesl_llvm_cbe_3_count);
  llvm_cbe_tmp__1 = (l_struct_OC_bench_args_t *)((l_struct_OC_bench_args_t *)llvm_cbe_vargs);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = bitcast i8* %%vargs to double*, !dbg !7 for 0x%llxth hint within @run_benchmark  --> \n", ++aesl_llvm_cbe_6_count);
  llvm_cbe_tmp__2 = (double *)((double *)llvm_cbe_vargs);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 1, i64 0, !dbg !7 for 0x%llxth hint within @run_benchmark  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__3 = (signed int *)(&llvm_cbe_tmp__1->field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 2, i64 0, !dbg !7 for 0x%llxth hint within @run_benchmark  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__4 = (signed int *)(&llvm_cbe_tmp__1->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 3, i64 0, !dbg !7 for 0x%llxth hint within @run_benchmark  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__5 = (double *)(&llvm_cbe_tmp__1->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 4, i64 0, !dbg !7 for 0x%llxth hint within @run_benchmark  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__6 = (double *)(&llvm_cbe_tmp__1->field4[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @apatb_spmv_sw(double* %%2, i32* %%3, i32* %%4, double* %%5, double* %%6) nounwind, !dbg !7 for 0x%llxth hint within @run_benchmark  --> \n", ++aesl_llvm_cbe_15_count);
   /*tail*/ apatb_spmv_sw((double *)llvm_cbe_tmp__2, (signed int *)llvm_cbe_tmp__3, (signed int *)llvm_cbe_tmp__4, (double *)llvm_cbe_tmp__5, (double *)llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @run_benchmark}\n");
  return;
}


void input_to_data(signed int llvm_cbe_fd,  char *llvm_cbe_vdata) {
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  l_struct_OC_bench_args_t *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
   char *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  double *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
   char *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  signed int *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
   char *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  signed int *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
   char *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  double *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @input_to_data\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8* %%vdata to %%struct.bench_args_t*, !dbg !5 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__7 = (l_struct_OC_bench_args_t *)((l_struct_OC_bench_args_t *)llvm_cbe_vdata);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memset(i8* %%vdata, i32 0, i64 29880 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_28_count);
  ( char *)memset(( char *)llvm_cbe_vdata, 0u, 29880ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%llX",29880ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__8);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i8* @readfile(i32 %%fd) nounwind, !dbg !4 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__9 = ( char *) /*tail*/ ( char *)readfile(llvm_cbe_fd);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i8* @find_section_start(i8* %%3, i32 1) nounwind, !dbg !8 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__10 = ( char *) /*tail*/ ( char *)find_section_start(( char *)llvm_cbe_tmp__9, 1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast i8* %%vdata to double*, !dbg !7 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__11 = (double *)((double *)llvm_cbe_vdata);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i32 @parse_double_array(i8* %%4, double* %%5, i32 1666) nounwind, !dbg !7 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_40_count);
   /*tail*/ parse_double_array(( char *)llvm_cbe_tmp__10, (double *)llvm_cbe_tmp__11, 1666u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1666u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call i8* @find_section_start(i8* %%3, i32 2) nounwind, !dbg !8 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__13 = ( char *) /*tail*/ ( char *)find_section_start(( char *)llvm_cbe_tmp__9, 2u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",2u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__13);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 1, i64 0, !dbg !7 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__14 = (signed int *)(&llvm_cbe_tmp__7->field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = tail call i32 @parse_int32_t_array(i8* %%7, i32* %%8, i32 1666) nounwind, !dbg !7 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_45_count);
   /*tail*/ parse_int32_t_array(( char *)llvm_cbe_tmp__13, (signed int *)llvm_cbe_tmp__14, 1666u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1666u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i8* @find_section_start(i8* %%3, i32 3) nounwind, !dbg !8 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__16 = ( char *) /*tail*/ ( char *)find_section_start(( char *)llvm_cbe_tmp__9, 3u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",3u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__16);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 2, i64 0, !dbg !8 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__17 = (signed int *)(&llvm_cbe_tmp__7->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = tail call i32 @parse_int32_t_array(i8* %%10, i32* %%11, i32 495) nounwind, !dbg !8 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_50_count);
   /*tail*/ parse_int32_t_array(( char *)llvm_cbe_tmp__16, (signed int *)llvm_cbe_tmp__17, 495u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",495u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__18);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = tail call i8* @find_section_start(i8* %%3, i32 4) nounwind, !dbg !8 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__19 = ( char *) /*tail*/ ( char *)find_section_start(( char *)llvm_cbe_tmp__9, 4u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",4u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 3, i64 0, !dbg !8 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__20 = (double *)(&llvm_cbe_tmp__7->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = tail call i32 @parse_double_array(i8* %%13, double* %%14, i32 494) nounwind, !dbg !8 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_55_count);
   /*tail*/ parse_double_array(( char *)llvm_cbe_tmp__19, (double *)llvm_cbe_tmp__20, 494u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",494u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__21);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%3) nounwind, !dbg !9 for 0x%llxth hint within @input_to_data  --> \n", ++aesl_llvm_cbe_56_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @input_to_data}\n");
  return;
}


void data_to_input(signed int llvm_cbe_fd,  char *llvm_cbe_vdata) {
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  l_struct_OC_bench_args_t *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  double *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  signed int *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  signed int *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  double *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @data_to_input\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8* %%vdata to %%struct.bench_args_t*, !dbg !6 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__22 = (l_struct_OC_bench_args_t *)((l_struct_OC_bench_args_t *)llvm_cbe_vdata);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i32 @write_section_header(i32 %%fd) nounwind, !dbg !4 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_75_count);
   /*tail*/ write_section_header(llvm_cbe_fd);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast i8* %%vdata to double*, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__24 = (double *)((double *)llvm_cbe_vdata);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i32 @write_double_array(i32 %%fd, double* %%3, i32 1666) nounwind, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_77_count);
   /*tail*/ write_double_array(llvm_cbe_fd, (double *)llvm_cbe_tmp__24, 1666u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nArgument  = 0x%X",1666u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 @write_section_header(i32 %%fd) nounwind, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_78_count);
   /*tail*/ write_section_header(llvm_cbe_fd);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 1, i64 0, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__27 = (signed int *)(&llvm_cbe_tmp__22->field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call i32 @write_int32_t_array(i32 %%fd, i32* %%6, i32 1666) nounwind, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_80_count);
   /*tail*/ write_int32_t_array(llvm_cbe_fd, (signed int *)llvm_cbe_tmp__27, 1666u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nArgument  = 0x%X",1666u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call i32 @write_section_header(i32 %%fd) nounwind, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_81_count);
   /*tail*/ write_section_header(llvm_cbe_fd);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__29);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 2, i64 0, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__30 = (signed int *)(&llvm_cbe_tmp__22->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i32 @write_int32_t_array(i32 %%fd, i32* %%9, i32 495) nounwind, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_83_count);
   /*tail*/ write_int32_t_array(llvm_cbe_fd, (signed int *)llvm_cbe_tmp__30, 495u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nArgument  = 0x%X",495u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__31);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call i32 @write_section_header(i32 %%fd) nounwind, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_84_count);
   /*tail*/ write_section_header(llvm_cbe_fd);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__32);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 3, i64 0, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__33 = (double *)(&llvm_cbe_tmp__22->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = tail call i32 @write_double_array(i32 %%fd, double* %%12, i32 494) nounwind, !dbg !5 for 0x%llxth hint within @data_to_input  --> \n", ++aesl_llvm_cbe_86_count);
   /*tail*/ write_double_array(llvm_cbe_fd, (double *)llvm_cbe_tmp__33, 494u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nArgument  = 0x%X",494u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__34);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @data_to_input}\n");
  return;
}


void output_to_data(signed int llvm_cbe_fd,  char *llvm_cbe_vdata) {
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  l_struct_OC_bench_args_t *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
   char *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
   char *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  double *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @output_to_data\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8* %%vdata to %%struct.bench_args_t*, !dbg !5 for 0x%llxth hint within @output_to_data  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__35 = (l_struct_OC_bench_args_t *)((l_struct_OC_bench_args_t *)llvm_cbe_vdata);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i8* @readfile(i32 %%fd) nounwind, !dbg !7 for 0x%llxth hint within @output_to_data  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__36 = ( char *) /*tail*/ ( char *)readfile(llvm_cbe_fd);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__36);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i8* @find_section_start(i8* %%2, i32 1) nounwind, !dbg !8 for 0x%llxth hint within @output_to_data  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__37 = ( char *) /*tail*/ ( char *)find_section_start(( char *)llvm_cbe_tmp__36, 1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 4, i64 0, !dbg !7 for 0x%llxth hint within @output_to_data  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__38 = (double *)(&llvm_cbe_tmp__35->field4[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 @parse_double_array(i8* %%3, double* %%4, i32 494) nounwind, !dbg !7 for 0x%llxth hint within @output_to_data  --> \n", ++aesl_llvm_cbe_103_count);
   /*tail*/ parse_double_array(( char *)llvm_cbe_tmp__37, (double *)llvm_cbe_tmp__38, 494u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",494u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%2) nounwind, !dbg !8 for 0x%llxth hint within @output_to_data  --> \n", ++aesl_llvm_cbe_104_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @output_to_data}\n");
  return;
}


void data_to_output(signed int llvm_cbe_fd,  char *llvm_cbe_vdata) {
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  l_struct_OC_bench_args_t *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  double *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @data_to_output\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8* %%vdata to %%struct.bench_args_t*, !dbg !5 for 0x%llxth hint within @data_to_output  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__40 = (l_struct_OC_bench_args_t *)((l_struct_OC_bench_args_t *)llvm_cbe_vdata);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i32 @write_section_header(i32 %%fd) nounwind, !dbg !4 for 0x%llxth hint within @data_to_output  --> \n", ++aesl_llvm_cbe_114_count);
   /*tail*/ write_section_header(llvm_cbe_fd);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__41);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 4, i64 0, !dbg !5 for 0x%llxth hint within @data_to_output  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__42 = (double *)(&llvm_cbe_tmp__40->field4[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i32 @write_double_array(i32 %%fd, double* %%3, i32 494) nounwind, !dbg !5 for 0x%llxth hint within @data_to_output  --> \n", ++aesl_llvm_cbe_116_count);
   /*tail*/ write_double_array(llvm_cbe_fd, (double *)llvm_cbe_tmp__42, 494u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument fd = 0x%X",llvm_cbe_fd);
printf("\nArgument  = 0x%X",494u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__43);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @data_to_output}\n");
  return;
}


signed int check_data( char *llvm_cbe_vdata,  char *llvm_cbe_vref) {
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  l_struct_OC_bench_args_t *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  l_struct_OC_bench_args_t *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  unsigned int llvm_cbe_tmp__46;
  unsigned int llvm_cbe_tmp__46__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  double *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  double llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  double *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  double llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  double llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  bool llvm_cbe_tmp__53;
  bool llvm_cbe_tmp__53__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @check_data\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8* %%vdata to %%struct.bench_args_t*, !dbg !5 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__44 = (l_struct_OC_bench_args_t *)((l_struct_OC_bench_args_t *)llvm_cbe_vdata);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = bitcast i8* %%vref to %%struct.bench_args_t*, !dbg !8 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__45 = (l_struct_OC_bench_args_t *)((l_struct_OC_bench_args_t *)llvm_cbe_vref);
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__46__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__58;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__58:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%18, %%14  for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__56);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi i32 [ 0, %%0 ], [ %%17, %%14  for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__46 = (unsigned int )llvm_cbe_tmp__46__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__46);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__55);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%storemerge1 to i64, !dbg !7 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__47 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.bench_args_t* %%1, i64 0, i32 4, i64 %%5, !dbg !7 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__48 = (double *)(&llvm_cbe_tmp__44->field4[(((signed long long )llvm_cbe_tmp__47))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__47));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load double* %%6, align 8, !dbg !7 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__49 = (double )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__49, *(long long*)(&llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.bench_args_t* %%2, i64 0, i32 4, i64 %%5, !dbg !7 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__50 = (double *)(&llvm_cbe_tmp__45->field4[(((signed long long )llvm_cbe_tmp__47))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__47));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load double* %%8, align 8, !dbg !7 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__51 = (double )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__51, *(long long*)(&llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = fsub double %%7, %%9, !dbg !7 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__52 = (double )llvm_cbe_tmp__49 - llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__52, *(long long*)(&llvm_cbe_tmp__52));
  if ((llvm_fcmp_olt(llvm_cbe_tmp__52, -0x1.0c6f7a0b5ed8dp-20))) {
    llvm_cbe_tmp__53__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    goto llvm_cbe_tmp__59;
  } else {
    goto llvm_cbe_tmp__60;
  }

llvm_cbe_tmp__59:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = phi i1 [ true, %%3 ], [ %%13, %%12  for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__53 = (bool )((llvm_cbe_tmp__53__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__53);
printf("\n = 0x%X",1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i1 %%15 to i32, !dbg !8 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__54 = (unsigned int )((unsigned int )(bool )llvm_cbe_tmp__53&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = or i32 %%16, %%4, !dbg !8 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__55 = (unsigned int )llvm_cbe_tmp__54 | llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge1, 1, !dbg !8 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__56&4294967295ull)));
  if (((llvm_cbe_tmp__56&4294967295U) == (494u&4294967295U))) {
    goto llvm_cbe_tmp__61;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__56;   /* for PHI node */
    llvm_cbe_tmp__46__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__55;   /* for PHI node */
    goto llvm_cbe_tmp__58;
  }

llvm_cbe_tmp__60:
  llvm_cbe_tmp__53__PHI_TEMPORARY = (bool )(llvm_fcmp_ogt(llvm_cbe_tmp__52, 0x1.0c6f7a0b5ed8dp-20));   /* for PHI node */
  goto llvm_cbe_tmp__59;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__61:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = zext i1 %%20 to i32, !dbg !8 for 0x%llxth hint within @check_data  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(bool )((llvm_cbe_tmp__55&4294967295U) == (0u&4294967295U))&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @check_data}\n");
  return llvm_cbe_tmp__57;
}

