import boto3
from aws_cdk import (
    aws_ec2 as ec2,
    aws_elasticloadbalancingv2 as elbv2,
)

vpc = ec2.Vpc(self, "VPC", max_azs=2)
alb = elbv2.ApplicationLoadBalancer(self, "ALB", vpc=vpc, internet_facing=True)
#Create a listener for alb
listener = elbv2.Listener(self, "LISTENER", protocol="TCP", port=80, ssl_certificate_id="SLCERT", load_balancer_arn=alb.arn)