require "AssessmentBase.rb"

module Validparen
  include AssessmentBase

  def assessmentInitialize(course)
    super("validparen",course)
    @problems = []
  end

end