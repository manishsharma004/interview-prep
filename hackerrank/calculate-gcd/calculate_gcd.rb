# frozen_string_literal: true

puts 'Running in ruby'

def min(first, second)
  first < second ? first : second
end

def max(first, second)
  first > second ? first : second
end

def gcd(first, second)
  first, second = min(first, second), max(first, second)

  first, second = second % first, first until (second % first).zero?

  first
end

def gcd_multiple(*numbers)
  numbers.reduce { |first, second| gcd(first, second) }
end

(0...gets.to_i).each do |_|
  numbers = gets.split.map(&:to_i)
  puts "gcd(#{numbers.join(', ')}) = #{gcd_multiple(*numbers)}"
end
