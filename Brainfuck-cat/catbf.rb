require "AssessmentBase.rb"

module Catbf
  include AssessmentBase

  def assessmentInitialize(course)
    super("catbf",course)
    @problems = []
  end

end
