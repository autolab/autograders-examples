require "AssessmentBase.rb"

module Csortlab
  include AssessmentBase

  def assessmentInitialize(course)
    super("csortlab",course)
    @problems = []
  end

end
