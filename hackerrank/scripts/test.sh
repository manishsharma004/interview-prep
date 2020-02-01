#!/bin/bash

if [ -z "$program_name" ]
then
	program_name=`basename "$PWD"`
fi

languages="java,python,ruby,cpp"

print_help() {
  echo "USAGE:
  test [-l PROGRAM_LANGUAGE] [-h]
  
  Options:
    -l: Programming language to test for. Available languages: ${languages}"
}

parse_arguments() {
  while getopts "p:l:h" opts; do
    case ${opts} in
      l)
        languages="$OPTARG"
      ;;
      h) print_help
        exit 0
      ;;
    esac
  done
}

parse_arguments $@


# Split languages comma separated string into individual languages
IFS=\, read -a languages <<<"$languages"

for language in "${languages[@]}"; do
  if [ $language == java ]; then
    java_program_name=`echo "$program_name" | awk -F"-" '{for(i=1;i<=NF;i++){$i=toupper(substr($i,1,1)) substr($i,2)}} 1' OFS=""`
    filename="${java_program_name}.java"
    if [[ -f $filename ]]; then
      bash test_java.sh
    else
      echo $filename not present
    fi
  fi
  if [ $language == cpp ]; then
    filename="${program_name}.cpp"
    if [[ -f $filename ]]; then
      bash test_cpp.sh
    else
      echo $filename not present
    fi
  fi
  if [ $language == python ]; then
    filename="${program_name}.py"
    if [[ -f $filename ]]; then
      bash test_python.sh
    else
      echo $filename not present
    fi
  fi
  if [ $language == ruby ]; then
    ruby_program_name=`echo "$program_name" | sed -r 's/(-)([a-z])/_\2/g'`
    filename="${ruby_program_name}.rb"
    if [[ -f $filename ]]; then
      bash test_ruby.sh
    else
      echo $filename not present
    fi
  fi
done
