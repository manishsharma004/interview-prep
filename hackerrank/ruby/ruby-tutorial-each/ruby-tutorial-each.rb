class User
  def update_score
    puts 'Score Updated'
  end
end

number_of_users = gets.to_i

users = (0...number_of_users).map { |i| User.new}

def scoring(array)
  array.each do |user|
    user.update_score
  end
end

scoring(users)
