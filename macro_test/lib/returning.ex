defmodule Returning do
	defmacro returning(val, do_block) do
		# IO.inspect do_block
		quote do
			value = unquote(val)
			case value, unquote(do_block)
			value
		end
	end
end