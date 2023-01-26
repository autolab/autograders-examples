require "AssessmentBase.rb"

module SolvesCryptarithm
  include AssessmentBase

  def assessmentInitialize(course)
    super("solvesCryptarithm",course)
    @problems = []
  end

end
