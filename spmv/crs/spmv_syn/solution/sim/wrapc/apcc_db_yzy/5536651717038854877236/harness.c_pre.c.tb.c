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
typedef struct l_struct_OC__IO_FILE l_struct_OC__IO_FILE;
typedef struct l_struct_OC__IO_marker l_struct_OC__IO_marker;
typedef struct l_struct_OC__IO_codecvt l_struct_OC__IO_codecvt;
typedef struct l_struct_OC__IO_wide_data l_struct_OC__IO_wide_data;

/* Structure contents */
struct l_struct_OC__IO_FILE {
  unsigned int field0;
   char *field1;
   char *field2;
   char *field3;
   char *field4;
   char *field5;
   char *field6;
   char *field7;
   char *field8;
   char *field9;
   char *field10;
   char *field11;
  l_struct_OC__IO_marker *field12;
  l_struct_OC__IO_FILE *field13;
  unsigned int field14;
  unsigned int field15;
  unsigned long long field16;
  unsigned short field17;
  unsigned char field18;
   char field19[1];
   char *field20;
  unsigned long long field21;
  l_struct_OC__IO_codecvt *field22;
  l_struct_OC__IO_wide_data *field23;
  l_struct_OC__IO_FILE *field24;
   char *field25;
  unsigned long long field26;
  unsigned int field27;
   char field28[20];
};

struct l_struct_OC__IO_marker {
};

struct l_struct_OC__IO_codecvt {
};

struct l_struct_OC__IO_wide_data {
};


/* External Global Variable Declarations */
extern unsigned int INPUT_SIZE;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(signed int llvm_cbe_argc,  char **llvm_cbe_argv);
void input_to_data(signed int ,  char *);
void run_benchmark( char *);
void data_to_output(signed int ,  char *);
void output_to_data(signed int ,  char *);
signed int check_data( char *,  char *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal_str[9] = "Success.";
static  char aesl_internal__OC_str9[12] = "output.data";
static  char aesl_internal__OC_str11[45] = "out_fd>0 && \"Couldn't open output data file\"";
static  char aesl_internal__OC_str2[37] = "/home/yzy/MachSuite/common/harness.c";
static  char aesl_internal__OC_str15[33] = "Benchmark results are incorrect\n";
static  char aesl_internal__OC_str4[11] = "check.data";
static  char aesl_internal__OC_str1[57] = "argc<4 && \"Usage: ./benchmark <input_file> <check_file>\"";
static  char aesl_internal___PRETTY_FUNCTION___OC_main[23] = "int main(int, char **)";
static  char aesl_internal__OC_str6[30] = "data!=NULL && \"Out of memory\"";
static  char aesl_internal__OC_str8[43] = "in_fd>0 && \"Couldn't open input data file\"";
static  char aesl_internal__OC_str3[11] = "input.data";
static  char aesl_internal__OC_str12[29] = "ref!=NULL && \"Out of memory\"";
static  char aesl_internal__OC_str14[46] = "check_fd>0 && \"Couldn't open check data file\"";


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

signed int main(signed int llvm_cbe_argc,  char **llvm_cbe_argv) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
   char **llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
   char **llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
   char *llvm_cbe_tmp__5;
   char *llvm_cbe_tmp__5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
   char *llvm_cbe_tmp__6;
   char *llvm_cbe_tmp__6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
   char *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
  if ((((signed int )llvm_cbe_argc) < ((signed int )4u))) {
    goto llvm_cbe_tmp__20;
  } else {
    goto llvm_cbe_tmp__21;
  }

llvm_cbe_tmp__21:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @__assert_fail(i8* getelementptr inbounds ([57 x i8]* @aesl_internal_.str1, i64 0, i64 0), i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str2, i64 0, i64 0), i32 21, i8* getelementptr inbounds ([23 x i8]* @aesl_internal___PRETTY_FUNCTION__.main, i64 0, i64 0)) noreturn nounwind, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_10_count);
   /*tail*/ __assert_fail(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 57
#endif
])), ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), 21u, ( char *)((&aesl_internal___PRETTY_FUNCTION___OC_main[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",21u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__20:
  if ((((signed int )llvm_cbe_argc) > ((signed int )1u))) {
    goto llvm_cbe_tmp__22;
  } else {
    llvm_cbe_tmp__5__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 11
#endif
]));   /* for PHI node */
    llvm_cbe_tmp__6__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 11
#endif
]));   /* for PHI node */
    goto llvm_cbe__2e_thread;
  }

llvm_cbe_tmp__22:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i8** %%argv, i64 1, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__1 = ( char **)(&llvm_cbe_argv[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8** %%6, align 8, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__2 = ( char *)*llvm_cbe_tmp__1;
  if ((((signed int )llvm_cbe_argc) > ((signed int )2u))) {
    goto llvm_cbe_tmp__23;
  } else {
    llvm_cbe_tmp__5__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__2;   /* for PHI node */
    llvm_cbe_tmp__6__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 11
#endif
]));   /* for PHI node */
    goto llvm_cbe__2e_thread;
  }

llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8** %%argv, i64 2, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__3 = ( char **)(&llvm_cbe_argv[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8** %%10, align 8, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__4 = ( char *)*llvm_cbe_tmp__3;
  llvm_cbe_tmp__5__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__2;   /* for PHI node */
  llvm_cbe_tmp__6__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__4;   /* for PHI node */
  goto llvm_cbe__2e_thread;

llvm_cbe__2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = phi i8* [ %%7, %%9 ], [ %%7, %%5 ], [ getelementptr inbounds ([11 x i8]* @aesl_internal_.str3, i64 0, i64 0), %%3  for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__5 = ( char *)llvm_cbe_tmp__5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = phi i8* [ %%11, %%9 ], [ getelementptr inbounds ([11 x i8]* @aesl_internal_.str4, i64 0, i64 0), %%5 ], [ getelementptr inbounds ([11 x i8]* @aesl_internal_.str4, i64 0, i64 0), %%3  for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__6 = ( char *)llvm_cbe_tmp__6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* @INPUT_SIZE, align 4, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__7 = (unsigned int )*(&INPUT_SIZE);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%14 to i64, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__8 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = tail call noalias i8* @malloc(i64 %%15) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__9 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",llvm_cbe_tmp__8);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__9);
}
  if (((llvm_cbe_tmp__9) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__24;
  } else {
    goto llvm_cbe_tmp__25;
  }

llvm_cbe_tmp__24:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @__assert_fail(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str6, i64 0, i64 0), i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str2, i64 0, i64 0), i32 37, i8* getelementptr inbounds ([23 x i8]* @aesl_internal___PRETTY_FUNCTION__.main, i64 0, i64 0)) noreturn nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_41_count);
   /*tail*/ __assert_fail(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), 37u, ( char *)((&aesl_internal___PRETTY_FUNCTION___OC_main[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",37u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__25:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = tail call i32 (i8*, i32, ...)* @open(i8* %%12, i32 0) nounwind, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__10 = (unsigned int ) /*tail*/ open(( char *)llvm_cbe_tmp__5, 0u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__10);
}
  if ((((signed int )llvm_cbe_tmp__10) > ((signed int )0u))) {
    goto llvm_cbe_tmp__26;
  } else {
    goto llvm_cbe_tmp__27;
  }

llvm_cbe_tmp__27:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @__assert_fail(i8* getelementptr inbounds ([43 x i8]* @aesl_internal_.str8, i64 0, i64 0), i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str2, i64 0, i64 0), i32 39, i8* getelementptr inbounds ([23 x i8]* @aesl_internal___PRETTY_FUNCTION__.main, i64 0, i64 0)) noreturn nounwind, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_49_count);
   /*tail*/ __assert_fail(( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 43
#endif
])), ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), 39u, ( char *)((&aesl_internal___PRETTY_FUNCTION___OC_main[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",39u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__26:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @input_to_data(i32 %%20, i8* %%16) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_51_count);
   /*tail*/ input_to_data(llvm_cbe_tmp__10, ( char *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__10);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @run_benchmark(i8* %%16) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_52_count);
   /*tail*/ run_benchmark(( char *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = tail call i32 (i8*, i32, ...)* @open(i8* getelementptr inbounds ([12 x i8]* @aesl_internal_.str9, i64 0, i64 0), i32 577, i32 438) nounwind, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__11 = (unsigned int ) /*tail*/ open(( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 12
#endif
])), 577u, 438u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",577u);
printf("\nArgument  = 0x%X",438u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__11);
}
  if ((((signed int )llvm_cbe_tmp__11) > ((signed int )0u))) {
    goto llvm_cbe_tmp__28;
  } else {
    goto llvm_cbe_tmp__29;
  }

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @__assert_fail(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str11, i64 0, i64 0), i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str2, i64 0, i64 0), i32 48, i8* getelementptr inbounds ([23 x i8]* @aesl_internal___PRETTY_FUNCTION__.main, i64 0, i64 0)) noreturn nounwind, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_60_count);
   /*tail*/ __assert_fail(( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), 48u, ( char *)((&aesl_internal___PRETTY_FUNCTION___OC_main[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",48u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @data_to_output(i32 %%24, i8* %%16) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_62_count);
   /*tail*/ data_to_output(llvm_cbe_tmp__11, ( char *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = tail call i32 @close(i32 %%24) nounwind, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_63_count);
   /*tail*/ close(llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__11);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* @INPUT_SIZE, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__13 = (unsigned int )*(&INPUT_SIZE);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sext i32 %%29 to i64, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__14 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = tail call noalias i8* @malloc(i64 %%30) nounwind, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__15 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",llvm_cbe_tmp__14);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__15);
}
  if (((llvm_cbe_tmp__15) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__30;
  } else {
    goto llvm_cbe_tmp__31;
  }

llvm_cbe_tmp__30:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @__assert_fail(i8* getelementptr inbounds ([29 x i8]* @aesl_internal_.str12, i64 0, i64 0), i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str2, i64 0, i64 0), i32 58, i8* getelementptr inbounds ([23 x i8]* @aesl_internal___PRETTY_FUNCTION__.main, i64 0, i64 0)) noreturn nounwind, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_74_count);
   /*tail*/ __assert_fail(( char *)((&aesl_internal__OC_str12[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 29
#endif
])), ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), 58u, ( char *)((&aesl_internal___PRETTY_FUNCTION___OC_main[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",58u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = tail call i32 (i8*, i32, ...)* @open(i8* %%13, i32 0) nounwind, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__16 = (unsigned int ) /*tail*/ open(( char *)llvm_cbe_tmp__6, 0u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__16);
}
  if ((((signed int )llvm_cbe_tmp__16) > ((signed int )0u))) {
    goto llvm_cbe_tmp__32;
  } else {
    goto llvm_cbe_tmp__33;
  }

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @__assert_fail(i8* getelementptr inbounds ([46 x i8]* @aesl_internal_.str14, i64 0, i64 0), i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str2, i64 0, i64 0), i32 60, i8* getelementptr inbounds ([23 x i8]* @aesl_internal___PRETTY_FUNCTION__.main, i64 0, i64 0)) noreturn nounwind, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_82_count);
   /*tail*/ __assert_fail(( char *)((&aesl_internal__OC_str14[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 46
#endif
])), ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), 60u, ( char *)((&aesl_internal___PRETTY_FUNCTION___OC_main[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",60u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @output_to_data(i32 %%35, i8* %%31) nounwind, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_84_count);
   /*tail*/ output_to_data(llvm_cbe_tmp__16, ( char *)llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__16);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = tail call i32 @check_data(i8* %%16, i8* %%31) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__17 = (unsigned int ) /*tail*/ check_data(( char *)llvm_cbe_tmp__9, ( char *)llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__17);
}
  if (((llvm_cbe_tmp__17&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__34;
  } else {
    goto llvm_cbe_tmp__35;
  }

llvm_cbe_tmp__34:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load %%struct._IO_FILE** @stderr, align 8, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__18 = (l_struct_OC__IO_FILE *)*(&stderr);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = tail call i64 @fwrite(i8* getelementptr inbounds ([33 x i8]* @aesl_internal_.str15, i64 0, i64 0), i64 32, i64 1, %%struct._IO_FILE* %%42), !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_89_count);
   /*tail*/ fwrite(( char *)((&aesl_internal__OC_str15[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 33
#endif
])), 32ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",32ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__19);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__36;

llvm_cbe_tmp__35:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%16) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_91_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%31) nounwind, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_92_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__36;

llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ 0, %%44 ], [ -1, %%41  for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",4294967295u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge;
}

