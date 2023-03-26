require "AssessmentBase.rb"

module Cvalidparen
  include AssessmentBase

  def assessmentInitialize(course)
    super("Cvalidparen",course)
    @problems = []
  end

end