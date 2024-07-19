#!/bin/bash
#
# @file build.sh
# @brief Script to build the main application and create libraries.
#
# This script sets up the environment and builds the main application executable
# and the associated shared and static libraries. It uses helper functions defined
# in helper.sh for various build-related tasks.
#
# @usage
# Run this script from the root of your project:
#   ./build.sh;


# Determine the directory of the script.
SCRIPT_DIR=$(dirname "$(readlink -f "$0")");
# Load helper functions
source "$SCRIPT_DIR/helper.sh";

# Specify the root path of the project.
PROJECT_PATH=$(pwd);

# Build 'matrixmath' project.
#
# This function builds the 'matrixmath' project, including the main application and libraries.
#
# Arguments:
#   $1 - Root path of the project.
#
# Usage:
#   build_matrixmath_project "/path/to/project";
build_matrixmath_project() {
  # Project Settings.
  local project_path="$1"; # Root path of the project.
  local base_name='libmatrixmath';   # Base name for the project.
  local test_dependencies='-lm'; # Dependencies for tests (add as needed).
  local library_dependencies='-lm'; # Dependencies for library (add as needed).
  local namespace=''; # The project namespace.

  # Build the project.
  build_project "$base_name" "$project_path" "$test_dependencies" "$library_dependencies" "$namespace";
}

# Build 'matrixmath' project.
build_matrixmath_project "$PROJECT_PATH";
