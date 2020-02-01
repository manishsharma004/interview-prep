# Opening Integer class to add method range?
class Integer
  # Check if current Integer is between range [lower, upper]
  def range?(lower, upper)
    self >= lower && self <= upper
  end
end

def in_range?(a, b, c)
  a.range?(b, c)
end

(0...gets.to_i).each do |_|
  a, b, c = gets.split.map(&:to_i)
  puts(in_range?(a, b, c))
end
