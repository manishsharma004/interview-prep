class Coder
  attr_reader :oh_one_count
  attr_reader :practised_count
  def initialize(oh_one_count)
    @oh_one_count = oh_one_count
    @practised_count = 0
  end

  def practice
    puts 'still not O(1)'
    @practised_count += 1
  end

  def oh_one?
    practised_count >= oh_one_count - 1
  end
end

coder = Coder.new(gets.to_i)

loop do
  break if coder.oh_one?
  coder.practice
end

puts 'finally O(1)'
