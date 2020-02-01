#!/bin/bash

program_name=''
languages="java,python,ruby,cpp"

print_help() {
  echo "USAGE:
  create_sample_problem_directory.sh [-p PROGRAM_NAME] [-l PROGRAM_LANGUAGE] [-h]"
}

parse_arguments() {
  while getopts "p:l:h" opts; do
    case ${opts} in
      p)
        program_name="$OPTARG"
      ;;
      l)
        languages="$OPTARG"
      ;;
      h) print_help ;;
    esac
  done
}

parse_arguments $@

# Check if program name is given
if [ -z $program_name ]; then
  echo "ERROR: program name not given."
  echo ""
  print_help
  exit 1
fi


# Split languages comma separated string into individual languages
IFS=\, read -a languages <<<"$languages"

mkdir -p -m 775 ${program_name}
mkdir -p -m 775 ${program_name}/inputs
touch ${program_name}/inputs/input-1.in

for language in "${languages[@]}"; do

  if [ $language == java ]; then
    java_program_name=`echo "$program_name" | awk -F"-" '{for(i=1;i<=NF;i++){$i=toupper(substr($i,1,1)) substr($i,2)}} 1' OFS=""`
    filename="${program_name}/${java_program_name}.java"
    touch "$filename"

    echo 'public class '${java_program_name}' {
    public static void main(String[] args) {
      System.out.printf("'${java_program_name}' java program\n");
    }
  }' >> "$filename"
  fi

  if [ $language == cpp ]; then
    filename="${program_name}/${program_name}.cpp"
    touch $filename
    echo '#include<iostream>

  int main() {
      std::cout << "'${program_name}' cpp program" << std::endl;
      return 0;
  }' >> $filename
  fi

  if [ $language == python ]; then
    filename="${program_name}/${program_name}.py"
    touch $filename
    echo "#!/usr/bin/env python

  print('${program_name} python program')" >> $filename
  fi

  if [ $language == ruby ]; then
    filename="${program_name}/${program_name}.rb"
    touch $filename
    echo "# frozen_string_literal: true

puts(\"sample ruby program\n\")
" >> $filename
  fi
done
