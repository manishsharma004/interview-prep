class User
  attr_reader :user_id

  def initialize(user_id)
    @user_id = user_id
  end

  def is_admin?
    user_id == 1
  end

  def update_score
    puts 'Score updated for non-admin!'
  end
end

number_of_users = gets.to_i

users = (0...number_of_users).map { |_| User.new(gets.to_i) }

def scoring(array)
  array.each do |user|
    puts 'Score not updated as the user is admin' if user.is_admin?
    user.update_score unless user.is_admin?
  end
end

scoring(users)
