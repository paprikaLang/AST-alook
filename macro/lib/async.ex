defmodule AsyncTask do
	defmacro sample(header, do: body) do
		quote do
			def unquote(header) do
				case @async do
					true -> spawn(fn -> unquote(body) end)
					_  -> 
						caller = self()
						spawn(fn -> send(caller, unquote(body)) end)

						receive do
							message -> message
						after
							@timeout -> @timeout_response
						end
				end
			end
		end
	end
end