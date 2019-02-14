defmodule MyIf do
	defmacro mif(condition, do: action) do
		quote do
			case unquote(condition) do
				true -> unquote(action)
				_    -> nil
			end
		end
	end
end