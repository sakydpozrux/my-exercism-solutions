
class Anagram
	def initialize(word)
		@word = word.downcase
		@pattern = @word.chars.sort
	end

	def match(words)
		matched = []

		words.each do |word|
			word_sorted = word.downcase.chars.sort
			matched << word if (word.downcase != @word && word_sorted == @pattern)
		end

		matched
	end
end