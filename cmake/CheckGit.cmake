# Inspired by: 	https://gitlab.com/jhamberg/cmake-examples
#		https://jonathanhamberg.com/post/cmake-embedding-git-hash/
#		https://ipenguin.ws/2012/11/cmake-automatically-use-git-tags-as.html
#		https://github.com/iPenguin/version_git
#		https://www.mattkeeter.com/blog/2018-01-06-versioning/


set(CURRENT_LIST_DIR ${CMAKE_CURRENT_LIST_DIR})
if (NOT DEFINED pre_configure_dir)
	set(pre_configure_dir ${CMAKE_CURRENT_LIST_DIR})
endif ()

if (NOT DEFINED post_configure_dir)
	set(post_configure_dir ${CMAKE_BINARY_DIR}/generated)
endif ()

set(pre_configure_file ${pre_configure_dir}/git_version.cpp.in)
set(post_configure_file ${post_configure_dir}/git_version.cpp)


#
#
function(CheckGitWrite git_describe git_hash git_diff git_branch)
	file(WRITE ${CMAKE_BINARY_DIR}/git-state.txt
		${git_describe}\n
		${git_hash}\n
		${git_diff}\n
		${git_branch}
	)
endfunction()


#
#
function(CheckGitVersion)
	execute_process(
		COMMAND git describe --tags --long --always #--dirty=-dirty
		WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
		OUTPUT_VARIABLE GIT_DESCRIBE
		ERROR_QUIET
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)

	# Get the latest abbreviated commit hash of the working branch
	execute_process(
		COMMAND git log -1 --format=%h
		WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
		OUTPUT_VARIABLE GIT_HASH
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)

	# Get "+" if there are uncommitted changes
	execute_process(
		COMMAND bash -c "git diff --quiet --exit-code || echo +"
		OUTPUT_VARIABLE GIT_DIFF
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)

	# Get current branch name
	execute_process(
		COMMAND git rev-parse --abbrev-ref HEAD
		OUTPUT_VARIABLE GIT_BRANCH
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)

	if (NOT EXISTS ${post_configure_dir})
		file(MAKE_DIRECTORY ${post_configure_dir})
	endif ()

	if (NOT EXISTS ${post_configure_dir}/git_version.h)
		file(COPY ${pre_configure_dir}/git_version.h DESTINATION ${post_configure_dir})
	endif()

	CheckGitWrite(${GIT_DESCRIBE} ${GIT_HASH} "${GIT_DIFF}" ${GIT_BRANCH})
	configure_file(${pre_configure_file} ${post_configure_file} @ONLY)
endfunction()


#
#
function(CheckGitSetup)
	add_custom_target(AlwaysCheckGit
		COMMAND ${CMAKE_COMMAND}
		-DRUN_CHECK_GIT_VERSION=1
		-Dpre_configure_dir=${pre_configure_dir}
		-Dpost_configure_file=${post_configure_dir}
		-P ${CURRENT_LIST_DIR}/CheckGit.cmake
		BYPRODUCTS ${post_configure_file}
		COMMENT "Checking git, generating git-version.cpp"
	)

	add_library(git-version ${CMAKE_BINARY_DIR}/generated/git_version.cpp)
	target_include_directories(git-version PUBLIC ${CMAKE_BINARY_DIR}/generated)
	add_dependencies(git-version AlwaysCheckGit)

	CheckGitVersion()
endfunction()


#
#
# This is used to run this function from an external cmake process.
if (RUN_CHECK_GIT_VERSION)
	CheckGitVersion()
endif ()


