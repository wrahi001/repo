#!/bin/sh
infile=waleed_860886521.txt
outfile1=$1".hh"
outfile2=$1".cc"


echo "#ifndef MyClass_hh
      #define MyClass_hh
      
      class MyClass
      {
	      public:
	      MyClass();
	      ~MyClass();
	      
	      private:
      };
      #endif" >> $outfile1

echo "#include \"./MyClass.hh\"

      MyClass::Myclass()
      {}
      
      MyClass::~MyClass()
      {}" >> $outfile2

