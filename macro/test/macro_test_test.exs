defmodule MacroTestTest do
  use ExUnit.Case
  doctest MacroTest
  import Returning

  test "a block returns its params" do
  	result = returning 5-2 do
  		value -> 
  			IO.puts "got #{value}"
  	end
    assert result == 3
  end

  test "returns pattern matching" do
  	result = returning {:ok, "tiyo"} do
  		{:error, _oops} ->
  			send self(), "no way"
  		{:ok, value} ->
  			send self(), "#{value}"
  	end
    assert result == {:ok, "tiyo"}
    assert_received "tiyo"
  end

  test "params execution" do
  	result = returning IO.inspect("hello, tiyo") do
  		value -> 
  			IO.puts "got value: #{value}"
  	end
    assert result == "hello, tiyo"
  end

end
