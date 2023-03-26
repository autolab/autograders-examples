require "AssessmentBase.rb"

module Cvalidparen
  include AssessmentBase

  def assessmentInitialize(course)
    super("validparen",course)
    @problems = []
  end

end