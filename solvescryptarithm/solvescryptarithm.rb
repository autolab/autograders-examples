require "AssessmentBase.rb"

module Solvescryptarithm
  include AssessmentBase

  def assessmentInitialize(course)
    super("solvescryptarithm",course)
    @problems = []
  end

end
