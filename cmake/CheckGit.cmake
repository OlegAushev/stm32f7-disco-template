#
#
#
function(CheckGitVersion)
execute_process(
	COMMAND bash -c "git diff --quiet --exit-code || echo +"
	OUTPUT_VARIABLE GIT_DIFF
)




endfunction()