defmodule Sample do
	import AsyncTask
	@async false
	@timeout 1000
	@timeout_response "no response"
	sample hello(name, timer \\ 10_000) do
		:timer.sleep(timer)
		"hello, #{name}"
	end
end